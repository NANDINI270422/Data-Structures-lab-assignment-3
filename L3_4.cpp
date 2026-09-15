
#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to give precedence of operators
int precedence(char op) {
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}

// Function to convert infix to postfix
string infixToPostfix(string infix) {
    stack<char> s;
    string postfix = "";

    for (char ch : infix) {

        // If operand, add directly to postfix
        if (isalnum(ch)) {
            postfix += ch;
        }

        // If opening parenthesis, push into stack
        else if (ch == '(') {
            s.push(ch);
        }

        // If closing parenthesis
        else if (ch == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }

            if (!s.empty())
                s.pop();  // Remove '('
        }

        // If operator
        else {
            while (!s.empty() &&
                   precedence(s.top()) >= precedence(ch)) {
                postfix += s.top();
                s.pop();
            }

            s.push(ch);
        }
    }

    // Pop remaining operators
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

int main() {
    string infix;

    cout << "Enter an infix expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);

    cout << "Postfix expression: " << postfix << endl;

    return 0;
}

