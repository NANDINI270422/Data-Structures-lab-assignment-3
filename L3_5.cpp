
#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

int main() {
    string postfix;
    stack<int> s;

    cout << "Enter postfix expression: ";
    cin >> postfix;

    for (char ch : postfix) {

        // If operand, push it into stack
        if (isdigit(ch)) {
            s.push(ch - '0');
        }

        // If operator
        else {
            int b = s.top();
            s.pop();

            int a = s.top();
            s.pop();

            int result;

            switch (ch) {
                case '+':
                    result = a + b;
                    break;

                case '-':
                    result = a - b;
                    break;

                case '*':
                    result = a * b;
                    break;

                case '/':
                    result = a / b;
                    break;

                case '^':
                    result = pow(a, b);
                    break;
            }

            s.push(result);
        }
    }

    cout << "Result = " << s.top() << endl;

    return 0;
}

