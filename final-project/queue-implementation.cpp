#include <iostream>
using namespace std;

#define MAX 5  // Maximum size of the queue

class Queue {
private:
    int arr[MAX];
    int front;
    int rear;
    int count;

public:
    // Constructor
    Queue() {
        front = 0;
        rear = -1;
        count = 0;
    }

    // Check if queue is empty
    bool isEmpty() {
        return count == 0;
    }

    // Check if queue is full
    bool isFull() {
        return count == MAX;
    }

    // Enqueue: Insert element at the rear
    void enqueue(int value) {
        if (isFull()) {
            cout << "\n  Queue Overflow! Cannot enqueue " << value << ". Queue is full.\n";
            return;
        }
        rear = (rear + 1) % MAX;   // circular increment
        arr[rear] = value;
        count++;
        cout << "\n  " << value << " enqueued successfully.\n";
    }

    // Dequeue: Remove element from the front
    void dequeue() {
        if (isEmpty()) {
            cout << "\n  Queue Underflow! Cannot dequeue. Queue is empty.\n";
            return;
        }
        cout << "\n  " << arr[front] << " dequeued from the queue.\n";
        front = (front + 1) % MAX;  // circular increment
        count--;
    }

    // Display all elements in the queue
    void display() {
        if (isEmpty()) {
            cout << "\n  Queue is empty. Nothing to display.\n";
            return;
        }
        cout << "\n  Queue (front --> rear): ";
        for (int i = 0; i < count; i++) {
            cout << arr[(front + i) % MAX];
            if (i != count - 1) cout << " -> ";
        }
        cout << "\n";
        cout << "  Front: " << arr[front]
             << "  |  Rear: " << arr[rear]
             << "  |  Size: " << count << "/" << MAX << "\n";
    }
};

int main() {
    Queue q;
    int choice, value;

    cout << "========================================\n";
    cout << "       QUEUE IMPLEMENTATION (Array)     \n";
    cout << "========================================\n";
    cout << "  Queue Capacity : " << MAX << " elements\n";
    cout << "  Type           : Circular Array Queue\n";
    cout << "========================================\n";

    do {
        cout << "\n----------- MENU -----------\n";
        cout << "  1. Enqueue (Insert)\n";
        cout << "  2. Dequeue (Remove)\n";
        cout << "  3. Display Queue\n";
        cout << "  4. Exit\n";
        cout << "-----------------------------\n";
        cout << "  Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "  Enter value to enqueue: ";
                cin >> value;
                q.enqueue(value);
                break;

            case 2:
                q.dequeue();
                break;

            case 3:
                q.display();
                break;

            case 4:
                cout << "\n  Exiting program. Goodbye!\n";
                cout << "========================================\n";
                break;

            default:
                cout << "\n  Invalid choice! Please enter 1-4.\n";
        }
    } while (choice != 4);

    return 0;
}