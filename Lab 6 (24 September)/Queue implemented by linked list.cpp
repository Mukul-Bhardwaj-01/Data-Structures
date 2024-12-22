#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    // Enqueue operation to add an element to the queue
    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << value << " enqueued into the queue." << endl;
    }

    // Dequeue operation to remove an element from the queue
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return -1; // Indicating error
        }
        int dequeuedValue = front->data;
        Node* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr; // Queue is empty
        }
        delete temp;
        cout << dequeuedValue << " dequeued from the queue." << endl;
        return dequeuedValue;
    }

    // Peek operation to view the front element without removing it
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty. No front element." << endl;
            return -1; // Indicating error
        }
        return front->data;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Display all elements in the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        Node* current = front;
        cout << "Queue elements: ";
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Destructor to free memory
    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};

int main() {
    Queue queue;
    int choice, value;

    do {
        cout << "\nMenu:" << endl;
        cout << "1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> value;
            queue.enqueue(value);
            break;

        case 2:
            queue.dequeue();
            break;

        case 3:
            value = queue.peek();
            if (value != -1) {
                cout << "Front element is: " << value << endl;
            }
            break;

        case 4:
            queue.display();
            break;

        case 5:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
