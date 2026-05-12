#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int e)
    {
        this->data = e;
        this->next = NULL;
    }
};

class LinkedList
{
public:
    Node *HEAD;
    int count = 0;

    LinkedList()
    {
        this->HEAD = NULL;
    }
    void insertAtBegining(){
        int ele;
        cout << "Enter the Element : ";
        cin >> ele;
        Node *current = new Node(ele);
        if (HEAD == NULL)
        {
            this->HEAD = current;
        }
        else
        {
            Node *ptr = new Node(ele);
            ptr->next = HEAD;
            HEAD = ptr;
        }
        count++;
        cout << "Insert Element at the Begining of the List Successfully...!" << endl;
                
    }
    void insertAtEnding(){
        int ele;
        cout << "Enter the Element : ";
        cin >> ele;
        Node *current = new Node(ele);
        if (HEAD == NULL)
        {
            this->HEAD = current;
        }
        else
        {
            Node *ptr = this->HEAD;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = current;
        }
        count++;
        cout << "Insert Element at the Ending of the List Successfully...!" << endl;
    }
    
    void deleteFromBegining()
    {

        if (this->HEAD == NULL && count == 0)
            {
                cout << "List Empty...!" << endl;
            }
            else
            {
                Node *temp = this->HEAD;
                this->HEAD = this->HEAD->next;
                delete temp;
                temp = NULL;
                count--;
                cout << "Element deleted from the begining of the list successfully.." << endl;
            }

    }
  
    void displayElement()
    {
        if (this->HEAD == NULL && count == 0)
        {
            cout << "List Empty...!" << endl;
        }
        else
        {
            Node *ptr = this->HEAD;
            cout << "Linked List Element : ";
            while (ptr != NULL)
            {
                cout << ptr->data << " ";
                ptr = ptr->next;
            }
            cout << endl;
        }
    }
    ~LinkedList() {
        Node *current = HEAD;
        while (current != NULL) {
            Node *next = current->next;
            delete current;
            current = next;
        }
    }
};

int main()
{

    LinkedList list;
    int choice;

    do
    {
        cout << endl;
        cout << "Singly Linked list operations " << endl;
        cout << "1. Insert Element at Begining" << endl;
        cout << "2. Insert Element at Ending" << endl;
        cout << "3. Delete Element from Begining " << endl;
        cout << "4. Display Linked List" << endl;
        cout << "0. Exit..." << endl;
        cout << "Enter your Choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            list.insertAtBegining();
            break;
        case 2:
            list.insertAtEnding();
            break;
        case 3:
            list.deleteFromBegining();
            break;
        case 4:
            list.displayElement();
            break;
        
        case 0:
            cout << "Thank You for Peforming Linked List Operation" << endl;
            break;
        default:
            cout << "Invalid Choice..." << endl;
            break;
        }
    } while (choice != 0);

    return 0;
}