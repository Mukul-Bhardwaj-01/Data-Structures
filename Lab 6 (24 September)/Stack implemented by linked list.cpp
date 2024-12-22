#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class Stack {
private:
    Node* top;

public:
    Stack() : top(nullptr) {}

    // Push operation to add an element to the stack
    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        cout << value << " pushed onto the stack." << endl;
    }

    // Pop operation to remove the top element from the stack
    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot pop." << endl;
            return -1; // Indicating error
        }
        int poppedValue = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        cout << poppedValue << " popped from the stack." << endl;
        return poppedValue;
    }

    // Peek operation to view the top element without removing it
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty. No top element." << endl;
            return -1; // Indicating error
        }
        return top->data;
    }

    // Check if the stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

    // Display all elements in the stack
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        Node* current = top;
        cout << "Stack elements: ";
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Destructor to free memory
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

int main() {
    Stack stack;
    int choice, value;

    do {
        cout << "\nMenu:" << endl;
        cout << "1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            stack.push(value);
            break;

        case 2:
            stack.pop();
            break;

        case 3:
            value = stack.peek();
            if (value != -1) {
                cout << "Top element is: " << value << endl;
            }
            break;

        case 4:
            stack.display();
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
