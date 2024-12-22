#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    // Function to add a node at the end of the list
    void append(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Function to get the maximum value in the list
    int getMaxValue() {
        if (!head) return 0;
        int maxVal = head->data;
        Node* current = head;
        while (current) {
            if (current->data > maxVal) {
                maxVal = current->data;
            }
            current = current->next;
        }
        return maxVal;
    }

    // Function to clear the list
    void clear() {
        Node* current = head;
        while (current) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = tail = nullptr;
    }

    // Function to extract all values into an array and clear the list
    vector<int> extractValues() {
        vector<int> values;
        Node* current = head;
        while (current) {
            values.push_back(current->data);
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = tail = nullptr;
        return values;
    }

    // Function to add values from an array back to the list
    void insertValues(const vector<int>& values) {
        for (int value : values) {
            append(value);
        }
    }

    // Function to display the list
    void display() {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Radix Sort implementation
    void radixSort() {
        if (!head) return;

        // Get the maximum value to determine the number of digits
        int maxVal = getMaxValue();
        int numDigits = log10(maxVal) + 1;

        // Create buckets for digits 0-9
        vector<LinkedList> buckets(10);

        int exp = 1; // Exponent to extract individual digits
        for (int i = 0; i < numDigits; ++i) {
            Node* current = head;

            // Distribute nodes into buckets based on the current digit
            while (current) {
                int digit = (current->data / exp) % 10;
                buckets[digit].append(current->data);
                current = current->next;
            }

            // Clear the current list and merge buckets back into the list
            clear();
            for (int j = 0; j < 10; ++j) {
                vector<int> values = buckets[j].extractValues();
                insertValues(values);
            }

            exp *= 10; // Move to the next digit
        }
    }

    ~LinkedList() {
        clear();
    }
};

int main() {
    LinkedList list;
    int n, value;

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the elements: \n";
    for (int i = 0; i < n; ++i) {
        cin >> value;
        list.append(value);
    }

    cout << "Original list: \n";
    list.display();

    list.radixSort();

    cout << "Sorted list: \n";
    list.display();

    return 0;
}
