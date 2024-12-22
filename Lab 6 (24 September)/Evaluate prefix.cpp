#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;

// Function to perform an operation on two operands
int performOperation(char operation, int operand1, int operand2) {
    switch (operation) {
    case '+':
        return operand1 + operand2;
    case '-':
        return operand1 - operand2;
    case '*':
        return operand1 * operand2;
    case '/':
        if (operand2 == 0) {
            cout << "Error: Division by zero." << endl;
            exit(1);
        }
        return operand1 / operand2;
    case '^':
        return pow(operand1, operand2);
    default:
        cout << "Error: Invalid operator " << operation << endl;
        exit(1);
    }
}

// Function to evaluate a prefix expression
int evaluatePrefix(const string& expression) {
    stack<int> stk;

    // Traverse the expression from right to left
    for (int i = expression.length() - 1; i >= 0; --i) {
        char ch = expression[i];

        if (isspace(ch)) {
            continue; // Skip whitespace
        }

        if (isdigit(ch)) {
            // If the character is a digit, push it onto the stack
            stk.push(ch - '0');
        } else {
            // If the character is an operator, pop two elements and apply the operation
            if (stk.size() < 2) {
                cout << "Error: Invalid prefix expression." << endl;
                exit(1);
            }
            int operand1 = stk.top();
            stk.pop();
            int operand2 = stk.top();
            stk.pop();

            int result = performOperation(ch, operand1, operand2);
            stk.push(result);
        }
    }

    if (stk.size() != 1) {
        cout << "Error: Invalid prefix expression." << endl;
        exit(1);
    }

    return stk.top();
}

int main() {
    string prefixExpression;

    cout << "Enter a prefix expression (e.g., +*23*54): ";
    cin >> prefixExpression;

    int result = evaluatePrefix(prefixExpression);
    cout << "The result of the prefix expression is: " << result << endl;

    return 0;
}
