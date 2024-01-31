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

void enqueue(Node*& front, Node*& rear, int data) {
    Node* newNode = createNode(data);
    if (rear == nullptr) {
        front = rear = newNode;
    } else {
        rear->link = newNode;
        rear = newNode;
    }
}

bool isEmpty(const Node* front) {
    return front == nullptr;
}

void dequeue(Node*& front, Node*& rear) {
    if (isEmpty(front)) {
        cout << "\nQueue Underflow" << endl;
        exit(1);
    } else {
        Node* temp = front;
        front = front->link;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
    }
}

int front(const Node* front) {
    if (!isEmpty(front))
        return front->data;
    else
        exit(1);
}

void display(const Node* front) {
    const Node* temp = front;
    while (temp != nullptr) {
        cout << temp->data;
        temp = temp->link;
        if (temp != nullptr)
            cout << " -> ";
    }
}

int getUserChoice() {
    int choice;
    cout << "\nQueue Operations:\n";
    cout << "1. Enqueue\n";
    cout << "2. Dequeue\n";
    cout << "3. Front\n";
    cout << "4. Display\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}

int main() {
    Node* front = nullptr;
    Node* rear = nullptr;
    int choice;

    do {
        choice = getUserChoice();

        switch (choice) {
            case 1: {
                int value;
                cout << "Enter value to enqueue: ";
                cin >> value;
                enqueue(front, rear, value);
                break;
            }
            case 2:
                dequeue(front, rear);
                break;
            case 3:
                cout << "Front element is " << front(front) << endl;
                break;
            case 4:
                display(front);
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
