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
    void insertElement()
    {
        int choice, pos, ele;
        do
        {
            cout << endl;
            cout << "Insert Operations..." << endl;
            cout << "1. Insert At the beginning of the list..." << endl;
            cout << "2. Insert At the ending of the list..." << endl;
            cout << "3. Insert At any position in the list..." << endl;
            cout << "0. Exit..." << endl;
            cout << "Enter your Choice : ";
            cin >> choice;
            switch (choice)
            {
            case 1:
            {
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
                break;
            }
            case 2:
            {
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
                break;
            }
            case 3:
            {
                cout << "Enter the Element : ";
                cin >> ele;
                cout << "Enter the Position : ";
                cin >> pos;
                if (pos > 0 && pos <= count + 1){
                    Node *current = new Node(ele);
                    if (pos == 0 || HEAD == NULL)
                    {
                        current->next = this->HEAD;
                        this->HEAD = current;
                    }
                    else
                    {
                        Node *ptr = HEAD;
                        for (int i = 1; i < pos - 1; i++)
                        {
                            ptr = ptr->next;
                        }
                        current->next = ptr->next;
                        ptr->next = current;
                    }
                    count++;
                    cout << "Insert Element at the given position of the List Successfully...!" << endl;
                }
                else
                {
                    cout << "Invalid Position...!" << endl;
                }
                break;
            }
            case 0:
            {
                cout << "Back to Main Menu" << endl;
                break;
            }
            default:
            {
                cout << "Invalid Choice...!" << endl;
                break;
            }
            }
        } while (choice != 0);
    }
    void updateElement()
    {
        if (this->HEAD == NULL && count == 0)
        {
            cout << "List Empty...!" << endl;
        }
        else
        {
            int pos, ele;
            cout << "Enter the Element : ";
            cin >> ele;
            cout << "Enter the Position : ";
            cin >> pos;
            if (pos > 0 && pos <= count)
            {
                Node *ptr = this->HEAD;
                for (int i = 1; i < pos; i++)
                {
                    ptr = ptr->next;
                }
                cout << pos << endl;
                cout << ele << endl;
                ptr->data = ele;
                cout << "Element Updated at the given position of the List Successfully...!" << endl;
            }
        }
    }
    void deleteElement()
    {
        int choice, pos;
        do
        {
            cout << endl;
            cout << "Delete Operations..." << endl;
            cout << "1. Delete from the beginning of the list..." << endl;
            cout << "2. Delete from the ending of the list..." << endl;
            cout << "3. Delete Element from At any position in the list..." << endl;
            cout << "0. Exit..." << endl;
            cout << "Enter your Choice : ";
            cin >> choice;
            switch (choice)
            {
            case 1:
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
                    cout << "Delete Element from the Begining of the List Successfully...!" << endl;
                }

                break;
            }
            case 2:
            {
                if (this->HEAD == NULL && count == 0)
                {
                    cout << "List Empty...!" << endl;
                }
                else
                {
                    Node *ptr = this->HEAD;
                    if (ptr->next == NULL)
                    {
                        delete ptr;
                        HEAD = NULL;
                    }
                    else
                    {
                        while (ptr->next->next != NULL)
                        {
                            ptr = ptr->next;
                        }
                        delete ptr->next;
                        ptr->next = NULL;
                    }
                    count--;
                    cout << "Delete Element at the Ending of the List Successfully...!" << endl;
                }
                break;
            }
            case 3:
            {
                if (this->HEAD == NULL && count == 0)
                {
                    cout << "List Empty...!" << endl;
                }
                else
                {
                    cout << "Enter the Position : ";
                    cin >> pos;
                    if (pos > 0 && pos <= count)
                    {
                        Node *ptr = this->HEAD;
                        Node *temp = this->HEAD;
                        for (int i = 1; i < pos - 1; i++)
                        {
                            ptr = ptr->next;
                        }
                        temp = ptr->next;
                        ptr->next = temp->next;
                        delete temp;
                        temp = NULL;
                        count--;
                        cout << "Delete Element from At any position in the list..." << endl;
                    }
                    else
                    {
                        cout << "Invalid Position" << endl;
                    }
                }
                break;
            }
            case 0:
            {
                cout << "Back to Main Menu" << endl;
                break;
            }
            default:
            {
                cout << "Invalid Choice...!" << endl;
                break;
            }
            }
        } while (choice != 0);
    }
    void countElement()
    {
        if (this->HEAD == NULL && count == 0)
        {
            cout << "List Empty...!" << endl;
        }
        else
        {
            cout << count << " Number of Elements in List...!" << endl;
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
        cout << "Memory Clean...!!" << endl;
    }
};

int main()
{

    LinkedList list;
    int choice;

    do
    {
        cout << endl;
        cout << "Linked List CRUD Operations..." << endl;
        cout << "1. Insert Element in Linked List..." << endl;
        cout << "2. Update Element in Linked List..." << endl;
        cout << "3. Delete Element from Linked List..." << endl;
        cout << "4. Display Linked List..." << endl;
        cout << "5. Count Element in the Linked List..." << endl;
        cout << "0. Exit..." << endl;
        cout << "Enter your Choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            list.insertElement();
            break;
        case 2:
            list.updateElement();
            break;
        case 3:
            list.deleteElement();
            break;
        case 4:
            list.displayElement();
            break;
        case 5:
            list.countElement();
            break;
        case 0:
            cout << "Thank You for Peforming Linked List Operation...!" << endl;
            break;
        default:
            cout << "Invalid Choice...!" << endl;
            break;
        }
    } while (choice != 0);

    return 0;
}