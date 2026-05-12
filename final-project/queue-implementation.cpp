#include <iostream>
using namespace std;


class Queue
{
    private:
        int front, rear, count, size, element;
        int *arr;

    public:

        Queue()
        {
            cout << "Enter queue size :";
            cin >> size;
            front = -1;
            rear = -1;
            count = 0;

            arr = new int[size];
        }
        void enqueue()
        {
            if (rear == size - 1)
            {
                cout << "Queue Overflow....." << endl;
            }
            else
            {
                cout << "Enter element : ";
                cin >> element;
                if (front == -1 && rear == -1)
                {
                    front++;
                    rear++;
                    arr[rear] = element;
                }
                else
                {
                    rear++;
                    arr[rear] = element;
                }
                count++;
                cout << "ELEMENT INSERTED IN THE QUEUE SUCCESSFULLY" << endl << endl;
            }
        }

        void dequeue()
        {
            if ((front == -1 && rear == -1) || front == rear + 1)
            {
                cout << "Queue Underflow....." << endl;
            }
            else
            {
                int temp;
                temp = arr[front];
                front++;
                count--;
                cout << "FRONT ELEMENT " << temp << " DELETED" << endl;
                if (front > rear)
                {
                    front = rear = -1;
                }
                cout << endl << endl;
            }
        }

        void display()
        {
        
            if ((front == -1 && rear == -1) || front > rear)
            {
                cout << "Queue Underflow....." << endl;
            }
            else
            {
                cout << "QUEUE ELEMENTS : ";
                for (int i = front; i <= rear; i++)
                {
                    cout << arr[i] << " ";
                }
                cout << endl << endl;
            }
        }
};

int main()
{
    Queue q;
    int choice, value;

    do
    {
        cout << endl << "* * * * QUEUE OPERATIONS * * * *" << endl;
        cout << "  1. Enqueue " << endl;
        cout << "  2. Dequeue " << endl;
        cout << "  3. Display Queue " << endl;
        cout << "  0. Exit" << endl;
        cout << "  Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            q.enqueue();
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            q.display();
            break;

        case 0:
            cout << "\n  Thankyou for performing queue operations!" << endl ;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 0);

    return 0;
}