#include <iostream>
using namespace std;


class Stack {
private:
    int top, size, count , element;
    int* arr;


public:
    Stack() {
        cout << "Enter Size of Stack : " ;
        cin >> size;
        top = -1;
        count = 0;

        arr = new int[size];
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == size - 1;
    }

    void pushInStack(int value) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << value << ". Stack is full." << endl;
        }
        else{ 
            top++;
            arr[top] = value;
            count++;
            cout << value << " pushed onto the stack successfully." << endl;
        }
    }

    void popFromStack() {
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop. Stack is empty." << endl;
        }
        else{     
            cout << arr[top--] << " popped from the stack successfully ." << endl;
            count--;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack Elements : ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
};

int main() {
    Stack s;
    int choice, value;

    do {
        cout << endl << "* * * * * Stack Operations* * * * * " << endl;
        cout << "1. Push Element in Stack" << endl;
        cout << "2. Pop An Element from Stack" << endl;
        cout << "3. Display All Stack Elements" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                s.pushInStack(value);
                break;
            case 2:
                s.popFromStack();
                break;
            case 3:
                s.display();
                break;
            case 0:
                cout << "Thankyou For Performing Stack Operations...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 0);

    return 0;
}