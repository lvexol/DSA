#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* link;
};

Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->link = nullptr;
    return newNode;
}

void push(Node*& top, int data) {
    Node* newNode = createNode(data);
    newNode->link = top;
    top = newNode;
}

bool isEmpty(const Node* top) {
    return top == nullptr;
}

int peek(const Node* top) {
    if (!isEmpty(top))
        return top->data;
    else
        exit(1);
}

void pop(Node*& top) {
    if (isEmpty(top)) {
        cout << "\nStack Underflow" << endl;
        exit(1);
    } else {
        Node* temp = top;
        top = top->link;
        delete temp;
    }
}

void display(const Node* top) {
    const Node* temp = top;
    while (temp != nullptr) {
        cout << temp->data;
        temp = temp->link;
        if (temp != nullptr)
            cout << " -> ";
    }
}

int getUserChoice() {
    int choice;
    cout << "\nStack Operations:\n";
    cout << "1. Push\n";
    cout << "2. Pop\n";
    cout << "3. Peek\n";
    cout << "4. Display\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}

int main() {
    Node* top = nullptr;
    int choice;

    do {
        choice = getUserChoice();

        switch (choice) {
            case 1: {
                int value;
                cout << "Enter value to push: ";
                cin >> value;
                push(top, value);
                break;
            }
            case 2:
                pop(top);
                break;
            case 3:
                cout << "Top element is " << peek(top) << endl;
                break;
            case 4:
                display(top);
                break;
            case 5:
                cout << "Exiting.\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 5);

    return 0;
}
