#include <iostream>
#include <vector>

using namespace std;

const int MAX_SIZE = 5; // Maximum size of the stack

void initializeStack(int stack[], int& top) {
    top = -1;
}


void push(int stack[], int& top, int value) {
    if (top==MAX_SIZE-1) {
        cout << "Stack Overflow! Cannot push element." << endl;
    } else {
        stack[++top] = value;
        cout << "Pushed " << value << " onto the stack." << endl;
    }
}

int pop(int stack[], int& top) {
    if (top==-1) {
        cout << "Stack Underflow! Cannot pop element." << endl;
        return -1; // Indicates an error or empty stack
    } else {
        int poppedElement = stack[top--];
        cout << "Popped " << poppedElement << " from the stack." << endl;
        return poppedElement;
    }
}

int peek(const int stack[], int top) {
    if (top==-1) {
        cout << "Stack is empty." << endl;
        return -1; // Indicates an error or empty stack
    } else {
        return stack[top];
    }
}

void display(const int stack[], int top) {
    if (top==-1) {
        cout << "Stack is empty." << endl;
    } else {
        cout << "Stack elements:" << endl;
        for (int i = top; i >= 0; --i) {
            cout << stack[i] << endl;
        }
    }
}

int main() {
    int stack[MAX_SIZE];
    int top;
    initializeStack(stack, top);

    int choice;
    do {
        cout << "\nStack Operations:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                int value;
                cout << "Enter the value to push: ";
                cin >> value;
                push(stack, top, value);
                break;
            case 2:
                pop(stack, top);
                break;
            case 3:
                cout << "Top of the stack: " << peek(stack, top) << endl;
                break;
            case 4:
                display(stack, top);
                break;
            case 5:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 5);

    return 0;
}
