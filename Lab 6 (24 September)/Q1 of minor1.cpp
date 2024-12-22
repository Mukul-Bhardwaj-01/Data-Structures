#include <iostream>
#include <cmath>
#include <iomanip> // for setting precision
using namespace std;

// Node structure for the linked list
struct Node {
    double x, y; // coordinates of the vertex
    Node* next;  // pointer to the next node

    Node(double x, double y) : x(x), y(y), next(nullptr) {}
};

// Linked list class to store the vertices of the polygon
class Polygon {
private:
    Node* head; // pointer to the head of the list

public:
    Polygon() : head(nullptr) {}

    // Function to add a vertex to the polygon
    void addVertex(double x, double y) {
        Node* newNode = new Node(x, y);
        if (!head) {
            head = newNode;
            head->next = head; // Make it circular
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    // Function to identify and print all edges
    void printEdges() {
        if (!head) return;

        Node* current = head;
        do {
            Node* nextNode = current->next;
            cout << "Edge: (" << current->x << ", " << current->y << ") -> (" << nextNode->x << ", " << nextNode->y << ")" << endl;
            current = nextNode;
        } while (current != head);
    }

    // Function to classify and print each edge as horizontal, vertical, or diagonal
    void classifyEdges() {
        if (!head) return;

        Node* current = head;
        do {
            Node* nextNode = current->next;
            cout << "Edge: (" << current->x << ", " << current->y << ") -> (" << nextNode->x << ", " << nextNode->y << ") is ";
            if (current->x == nextNode->x) {
                cout << "Vertical" << endl;
            } else if (current->y == nextNode->y) {
                cout << "Horizontal" << endl;
            } else {
                cout << "Diagonal" << endl;
            }
            current = nextNode;
        } while (current != head);
    }

    // Function to calculate and print the length of each edge
    void calculateEdgeLengths() {
        if (!head) return;

        Node* current = head;
        do {
            Node* nextNode = current->next;
            double length = sqrt(pow(nextNode->x - current->x, 2) + pow(nextNode->y - current->y, 2));
            cout << "Length of edge (" << current->x << ", " << current->y << ") -> (" << nextNode->x << ", " << nextNode->y << "): "
                 << fixed << setprecision(2) << length << endl;
            current = nextNode;
        } while (current != head);
    }

    // Destructor to free memory
    ~Polygon() {
        if (!head) return;

        Node* current = head;
        do {
            Node* temp = current;
            current = current->next;
            delete temp;
        } while (current != head);
    }
};

int main() {
    Polygon polygon;

    // Adding vertices to the polygon
    polygon.addVertex(2, 2);
    polygon.addVertex(8, 2);
    polygon.addVertex(10, 4);
    polygon.addVertex(8, 6);
    polygon.addVertex(2, 6);
    polygon.addVertex(0, 4);
    polygon.addVertex(2, 2); // Closing the polygon

    cout << "\nEdges of the polygon:" << endl;
    polygon.printEdges();

    cout << "\nClassification of edges:" << endl;
    polygon.classifyEdges();

    cout << "\nLengths of edges:" << endl;
    polygon.calculateEdgeLengths();

    return 0;
}
