#include <iostream>
#include <vector>

using namespace std;

const int MAX_SIZE = 5;

void initializeQueue(int queue[], int& front, int& rear) {
    front = rear = -1;
}

bool isEmpty(int front, int rear) {
    return front == -1 || front > rear;
}

bool isFull(int rear) {
    return rear == MAX_SIZE - 1;
}

void enqueue(int queue[], int& front, int& rear, int value) {
    if (isFull(rear)) {
        cout << "Overflow!" << endl;
    } else {
        if (front == -1) front = 0;
        queue[++rear] = value;
        cout << "Enqueued " << value << endl;
    }
}

int dequeue(int queue[], int& front, int& rear) {
    if (isEmpty(front, rear)) {
        cout << "Underflow!" << endl;
        return -1;
    } else {
        int dequeuedElement = queue[front++];
        cout << "Dequeued " << dequeuedElement << endl;
        return dequeuedElement;
    }
}

int front(const int queue[], int front) {
    if (isEmpty(front, front)) {
        cout << "Empty!" << endl;
        return -1;
    } else {
        return queue[front];
    }
}

void display(const int queue[], int front, int rear) {
    if (isEmpty(front, rear)) {
        cout << "Empty!" << endl;
    } else {
        cout << "Queue elements:" << endl;
        for (int i = front; i <= rear; ++i) {
            cout << queue[i] << endl;
        }
    }
}

int main() {
    int queue[MAX_SIZE];
    int front, rear;
    initializeQueue(queue, front, rear);

    int choice;
    do {
        cout << "\nQueue Operations:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Front\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                int value;
                cout << "Enter value: ";
                cin >> value;
                enqueue(queue, front, rear, value);
                break;
            case 2:
                dequeue(queue, front, rear);
                break;
            case 3:
                cout << "Front: " << front(queue, front) << endl;
                break;
            case 4:
                display(queue, front, rear);
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
