//30 July Q2 solution
/*You are given a list of n consecutive integers starting from a given number.
One integer is missing from this list due to an error.
Find and print the missing integer. 
Do not use any arithmetic operation.*/

#include <iostream>
using namespace std;

int findMissingInteger(int start, int n, int A[]) {
    int totalXOR = 0;
    int listXOR = 0;

    // XOR all integers from start to start + n - 1
    for (int i = start; i < start + n; i++) {
        totalXOR ^= i;
    }

    // XOR all integers in the provided list
    for (int i = 0; i < n - 1; i++) {
        listXOR ^= A[i];
    }

    // The missing number will be the XOR of both results
    return totalXOR ^ listXOR;
}

int main() {
    int start_num, n;
    cout << "Enter the starting number: ";
    cin >> start_num;
    cout << "Enter the total number of elements (including the missing one) : ";
    cin >> n;

    int A[n - 1]; 
    cout << "Enter the " << n - 1 << " consecutive integers (with the error of one missing):\n";
    for (int i = 0; i < n - 1; i++) {
        cin >> A[i];
    }

    int missingInteger = findMissingInteger(start_num, n, A);
    cout << "The missing integer is: " << missingInteger << endl;

    return 0;
}
