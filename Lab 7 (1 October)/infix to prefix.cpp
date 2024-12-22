#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

// Function to determine precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}

// Function to check if a character is an operator
bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

// Function to convert infix to prefix
string infixToPrefix(const string& infix) {
    stack<char> operators;
    stack<string> operands;

    for (char ch : infix) {
        if (isspace(ch)) {
            continue; // Skip whitespace
        }

        if (isalnum(ch)) {
            // If operand, push it onto the operands stack
            operands.push(string(1, ch));
        } else if (ch == '(') {
            // If '(', push onto operators stack
            operators.push(ch);
        } else if (ch == ')') {
            // If ')', pop and process until '(' is found
            while (!operators.empty() && operators.top() != '(') {
                string operand2 = operands.top();
                operands.pop();
                string operand1 = operands.top();
                operands.pop();
                char op = operators.top();
                operators.pop();

                // Form prefix expression and push back
                string prefix = op + operand1 + operand2;
                operands.push(prefix);
            }
            if (!operators.empty() && operators.top() == '(') {
                operators.pop(); // Remove '(' from stack
            }
        } else if (isOperator(ch)) {
            // If operator, process based on precedence
            while (!operators.empty() && precedence(operators.top()) >= precedence(ch)) {
                string operand2 = operands.top();
                operands.pop();
                string operand1 = operands.top();
                operands.pop();
                char op = operators.top();
                operators.pop();

                // Form prefix expression and push back
                string prefix = op + operand1 + operand2;
                operands.push(prefix);
            }
            operators.push(ch);
        }
    }

    // Process remaining operators
    while (!operators.empty()) {
        string operand2 = operands.top();
        operands.pop();
        string operand1 = operands.top();
        operands.pop();
        char op = operators.top();
        operators.pop();

        // Form prefix expression and push back
        string prefix = op + operand1 + operand2;
        operands.push(prefix);
    }

    // The final prefix expression is in the operands stack
    return operands.top();
}

int main() {
    string infixExpression;

    cout << "Enter an infix expression: ";
    getline(cin, infixExpression);

    string prefixExpression = infixToPrefix(infixExpression);
    cout << "The prefix expression is: " << prefixExpression << endl;

    return 0;
}
