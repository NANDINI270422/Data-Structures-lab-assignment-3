#include <iostream>
using namespace std;

#define MAX 5

class Stack
{
    int arr[MAX];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    // (i) Push operation
    void push(int value)
    {
        if (isFull())
        {
            cout << "Stack Overflow! Stack is full.\n";
        }
        else
        {
            top++;
            arr[top] = value;
            cout << value << " pushed into the stack.\n";
        }
    }

    // (ii) Pop operation
    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow! Stack is empty.\n";
        }
        else
        {
            cout << arr[top] << " popped from the stack.\n";
            top--;
        }
    }

    // (iii) Check if stack is empty
    bool isEmpty()
    {
        return top == -1;
    }

    // (iv) Check if stack is full
    bool isFull()
    {
        return top == MAX - 1;
    }

    // (v) Display stack
    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is empty.\n";
        }
        else
        {
            cout << "Stack elements are:\n";
            for (int i = top; i >= 0; i--)
            {
                cout << arr[i] << endl;
            }
        }
    }

    // (vi) Peek operation
    void peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty.\n";
        }
        else
        {
            cout << "Top element is: " << arr[top] << endl;
        }
    }
};

int main()
{
    Stack s;
    int choice, value;

    do
    {
        cout << "\n----- STACK MENU -----\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Is Empty\n";
        cout << "4. Is Full\n";
        cout << "5. Display\n";
        cout << "6. Peek\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            s.push(value);
            break;

        case 2:
            s.pop();
            break;

        case 3:
            if (s.isEmpty())
                cout << "Stack is empty.\n";
            else
                cout << "Stack is not empty.\n";
            break;

        case 4:
            if (s.isFull())
                cout << "Stack is full.\n";
            else
                cout << "Stack is not full.\n";
            break;

        case 5:
            s.display();
            break;

        case 6:
            s.peek();
            break;

        case 7:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 7);

    return 0;
}



