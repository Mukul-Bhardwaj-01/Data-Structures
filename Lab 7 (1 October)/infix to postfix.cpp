#include <iostream>
#include <stack>
#include <string>
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

// Function to convert infix to postfix
string infixToPostfix(const string& infix) {
    stack<char> stk;
    string postfix = "";

    for (char ch : infix) {
        if (isspace(ch)) {
            continue; // Skip whitespace
        }

        if (isalnum(ch)) {
            // If operand, add to postfix expression
            postfix += ch;
        } else if (ch == '(') {
            // If '(', push onto stack
            stk.push(ch);
        } else if (ch == ')') {
            // If ')', pop and add to postfix until '(' is found
            while (!stk.empty() && stk.top() != '(') {
                postfix += stk.top();
                stk.pop();
            }
            if (!stk.empty() && stk.top() == '(') {
                stk.pop(); // Remove '(' from stack
            }
        } else if (isOperator(ch)) {
            // If operator, pop operators with higher or equal precedence
            while (!stk.empty() && precedence(stk.top()) >= precedence(ch)) {
                postfix += stk.top();
                stk.pop();
            }
            stk.push(ch);
        }
    }

    // Pop any remaining operators in the stack
    while (!stk.empty()) {
        postfix += stk.top();
        stk.pop();
    }

    return postfix;
}

int main() {
    string infixExpression;

    cout << "Enter an infix expression: ";
    getline(cin, infixExpression);

    string postfixExpression = infixToPostfix(infixExpression);
    cout << "The postfix expression is: " << postfixExpression << endl;

    return 0;
}
