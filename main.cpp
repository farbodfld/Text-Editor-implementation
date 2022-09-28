#include <iostream>

using namespace std;

#define MAX 1000000

class Stack {
    int top;
    char a[MAX];

public:
    Stack() {
        top = -1;
    }

    bool push(int x) {
        if (top >= (MAX - 1)) {
            return false;
        } else {
            a[++top] = x;
            return true;
        }
    }

    int pop() {
        if (top < 0) {
            return 0;
        } else {
            int x = a[top--];
            return x;
        }
    }

    int peek() {
        if (top < 0) {
            return 0;
        } else {
            int x = a[top];
            return x;
        }
    }

    bool isEmpty() {
        return (top < 0);
    }

    void display() {
        if (isEmpty())
            cout << "-1";
        else
            for (int i = top; i >= 0; i--)
                cout << a[i];


    }
};


void editText(string inputString) {
    Stack stack1, helpingStack;

    int size = 0;
    while (inputString[size])
        size++;

    for (int i = 0; i < size; i++) {

        if (inputString[i] != '<' && inputString[i] != '>' && inputString[i] != '-')
            stack1.push(inputString[i]);

        else if (inputString[i] == '<') {
            if (!stack1.isEmpty())
                helpingStack.push(stack1.pop());

        }
        else if (inputString[i] == '>') {
            if (!helpingStack.isEmpty())
                stack1.push(helpingStack.pop());
        }
        else if (inputString[i] == '-') {
            if (!stack1.isEmpty())
                stack1.pop();
        }
    }

    while (!helpingStack.isEmpty())
        stack1.push(helpingStack.pop());

    while (!stack1.isEmpty())
        helpingStack.push(stack1.pop());

    helpingStack.display();
}

int main() {
    string s;
    cin >> s;
    editText(s);
}