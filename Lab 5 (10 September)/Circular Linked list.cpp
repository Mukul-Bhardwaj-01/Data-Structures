/*Design a circular linked list using class and perform
Search, Update, Insert and Delete operations on it
based on user specifications.*/

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value){ 
      data=value; 
      next=nullptr; }
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() {
      head=nullptr; }

    // Insert a node at the end of the list
    void insert(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            head->next = head; // Point to itself
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    // Search for a node with the given value
    Node* search(int value) {
        if (!head) return nullptr;

        Node* temp = head;
        do {
            if (temp->data == value) return temp;
            temp = temp->next;
        } while (temp != head);

        return nullptr; // Value not found
    }

    // Update the value of a node
    bool update(int oldValue, int newValue) {
        Node* targetNode = search(oldValue);
        if (targetNode) {
            targetNode->data = newValue;
            return true;
        }
        return false;
    }

    // Delete a node with the given value
    bool deleteNode(int value) {
        if (!head) return false;

        Node* current = head;
        Node* prev = nullptr;

        do {
            if (current->data == value) {
                if (current == head && current->next == head) {
                    // Single node case
                    delete head;
                    head = nullptr;
                } else {
                    if (current == head) {
                        // Update head pointer
                        Node* temp = head;
                        while (temp->next != head) {
                            temp = temp->next;
                        }
                        temp->next = head->next;
                        head = head->next;
                    } else {
                        prev->next = current->next;
                    }
                    delete current;
                }
                return true;
            }
            prev = current;
            current = current->next;
        } while (current != head);

        return false; // Value not found
    }

    // Display the list
    void display() {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }

    // Destructor to free memory
    ~CircularLinkedList() {
        if (!head) return;

        Node* current = head;
        Node* nextNode;

        do {
            nextNode = current->next;
            delete current;
            current = nextNode;
        } while (current != head);

        head = nullptr;
    }
};

int main() {
    CircularLinkedList list;
    int choice, value, oldValue, newValue;

    do {
        cout << "\nMenu:" << endl;
        cout << "1. Insert\n2. Search\n3. Update\n4. Delete\n5. Display\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            list.insert(value);
            break;

        case 2:
            cout << "Enter value to search: ";
            cin >> value;
            if (list.search(value)) {
                cout << "Value " << value << " found in the list." << endl;
            } else {
                cout << "Value " << value << " not found in the list." << endl;
            }
            break;

        case 3:
            cout << "Enter value to update: ";
            cin >> oldValue;
            cout << "Enter new value: ";
            cin >> newValue;
            if (list.update(oldValue, newValue)) {
                cout << "Value updated successfully." << endl;
            } else {
                cout << "Value not found in the list." << endl;
            }
            break;

        case 4:
            cout << "Enter value to delete: ";
            cin >> value;
            if (list.deleteNode(value)) {
                cout << "Value deleted successfully." << endl;
            } else {
                cout << "Value not found in the list." << endl;
            }
            break;

        case 5:
            cout << "List contents: ";
            list.display();
            break;

        case 6:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}
