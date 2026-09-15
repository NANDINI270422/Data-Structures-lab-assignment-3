#include <iostream>
#include <string>
using namespace std;

#define MAX 100

class Stack
{
    char arr[MAX];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    void push(char ch)
    {
        if (top == MAX - 1)
        {
            cout << "Stack Overflow!";
        }
        else
        {
            arr[++top] = ch;
        }
    }

    char pop()
    {
        if (top == -1)
        {
            return '\0';
        }
        else
        {
            return arr[top--];
        }
    }

    bool isEmpty()
    {
        return top == -1;
    }
};

int main()
{
    Stack s;
    string str, reversed = "";

    cout << "Enter a string: ";
    cin >> str;

    // Push each character into the stack
    for (char ch : str)
    {
        s.push(ch);
    }

    // Pop characters to reverse the string
    while (!s.isEmpty())
    {
        reversed += s.pop();
    }

    cout << "Reversed string: " << reversed << endl;

    return 0;
}