#include <iostream>
using namespace std;

// Function to display a single move
void move(char from, char to) {
    cout << "Move from " << from << " to " << to << endl;
}

// Recursive Tower of Hanoi function
void TOH(int n, char from, char aux, char to, int &count) {
    if (n == 1) {
        count++;
        move(from, to); // Move the single disk directly
    } else {
        TOH(n - 1, from, to, aux, count); // Move n-1 disks from 'from' to 'aux'
        count++;
        move(from, to);                  // Move the nth disk from 'from' to 'to'
        TOH(n - 1, aux, from, to, count); // Move n-1 disks from 'aux' to 'to'
    }
}

int main() {
    int n; // Number of disks
    cout << "Enter the number of disks: ";
    cin >> n;

    int count = 0; // Variable to count the total moves
    cout << "The sequence of moves is:\n";
    TOH(n, 'A', 'B', 'C', count); // Solve the puzzle, using rods A, B, C

    cout << "\nTotal moves: " << count << endl;
    return 0;
}
