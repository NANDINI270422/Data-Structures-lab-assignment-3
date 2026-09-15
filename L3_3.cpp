
#include <iostream>
#include <stack>
using namespace std;

bool isBalanced(string exp) {
    stack<char> s;

    for (char ch : exp) {

        // Opening brackets
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        }

        // Closing brackets
        else if (ch == ')' || ch == '}' || ch == ']') {

            // No opening bracket available
            if (s.empty()) {
                return false;
            }

            char top = s.top();
            s.pop();

            // Check matching brackets
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false;
            }
        }
    }

    // If stack is empty, brackets are balanced
    return s.empty();
}

int main() {
    string exp;

    cout << "Enter an expression: ";
    cin >> exp;

    if (isBalanced(exp))
        cout << "Expression has balanced parentheses." << endl;
    else
        cout << "Expression does not have balanced parentheses." << endl;

    return 0;
}

