#include <iostream>
using namespace std;

class CircularQueue {
private:
    int *queue; // Array to store queue elements
    int front;  // Points to the frontmost element
    int rear;   // Points to the rearmost element
    int size;   // Maximum capacity of the queue
    int count;  // Current number of elements in the queue

public:
    // Constructor
    CircularQueue(int capacity) {
        size = capacity;
        queue = new int[size];
        front = 0;
        rear = -1;
        count = 0;
    }

    // Destructor
    ~CircularQueue() {
        delete[] queue;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return count == 0;
    }

    // Check if the queue is full
    bool isFull() {
        return count == size;
    }

    // Add an element to the queue
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue " << value << ".\n";
            return;
        }
        rear = (rear + 1) % size; // Move rear pointer circularly
        queue[rear] = value;
        count++;
        cout << value << " enqueued successfully.\n";
    }

    // Remove an element from the queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue.\n";
            return;
        }
        cout << queue[front] << " dequeued successfully.\n";
        front = (front + 1) % size; // Move front pointer circularly
        count--;
    }

    // Get the frontmost element
    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return -1;
        }
        return queue[front];
    }

    // Get the rearmost element
    int getRear() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return -1;
        }
        return queue[rear];
    }

    // Display the queue elements
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Queue elements: ";
        for (int i = 0; i < count; i++) {
            cout << queue[(front + i) % size] << " ";
        }
        cout << endl;
    }
};

int main() {
    int capacity;
    cout << "Enter the capacity of the circular queue: ";
    cin >> capacity;

    CircularQueue cq(capacity);

    int choice, value;
    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Get Front\n";
        cout << "4. Get Rear\n";
        cout << "5. Display Queue\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> value;
            cq.enqueue(value);
            break;
        case 2:
            cq.dequeue();
            break;
        case 3:
            cout << "Frontmost element: " << cq.getFront() << endl;
            break;
        case 4:
            cout << "Rearmost element: " << cq.getRear() << endl;
            break;
        case 5:
            cq.display();
            break;
        case 6:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
