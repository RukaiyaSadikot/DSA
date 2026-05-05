#include<iostream>
using namespace std;

class Node{       
    public:
        int data;
        Node *next;
        Node(int data){
            this->data=data;
            this->next=NULL;
        }
};

class LinkedList{         
    public:
        Node *Head;
        int count=0;

        LinkedList(){          
            this->Head=NULL;
        }
        bool isEmpty(){        
            if(Head==NULL){
                return true;
            }
            else{
                return false;
            }
        }
        void insertAtBeginning(int data){           
            Node *n=new Node(data);

            n->next=Head;
            Head=n;
            count++;
                        
            cout<<endl<<"ELEMENT INSERTED"<<endl;
        }
        void search(int value){           
            int position=0;
            bool found=false;
            Node *ptr=NULL;
            ptr=Head;

            while(ptr!=nullptr){
                position++;
                if(ptr->data==value){
                    cout<<endl<<"VALUE "<<value<<" IS AT "<<position<<" POSITION"<<endl;
                    found=true;
                }
                ptr=ptr->next;
            }

            if(!found){
                cout<<endl<<"VALUE "<<value<<" IS NOT IN LINKED LIST"<<endl;
            }
        }
        void deleteNode(int value){         
            int position=0;
            Node *current=Head;
            Node *prev=NULL;
            bool found=false;

            while(current!=NULL){
                position++;
                if(current->data==value){
                    if(position==1){
                        Head=current->next;
                    }
                    else{
                        prev->next=current->next;
                    }
                    delete current;
                    current=nullptr;

                    found=true;
                    count--;
                    cout<<endl<<"NODE WITH "<<value<<" VALUE IS DELETED"<<endl;

                    break;
                }
                prev=current;
                current=current->next;
            }

            if(!found){
                cout<<endl<<"NODE WITH "<<value<<" VALUE IS NOT FOUND IN LINKED LIST"<<endl<<endl;
            }
        }
        void reverse(){        
            Node *ptr=Head;
            cout<<endl<<"LINKED LIST : ";
            while(ptr!=NULL){
                cout<<ptr->data<<" ";
                ptr=ptr->next;
            }
            cout<<endl;

            Node *prev=nullptr, *current=Head, *next=nullptr;
            while(current!=nullptr){
                next=current->next; 
                current->next=prev;       
                prev=current;        
                current=next;       
            }
            Head=prev;          
            ptr=Head;

            cout<<endl<<"REVERSE LINKED LIST : ";
            while(ptr!=NULL){
                cout<<ptr->data<<" ";
                ptr=ptr->next;
            }

            cout<<endl;
        }
        void display(){         
            Node *ptr=Head;
            cout<<endl<<"LINKED LIST ELEMENTS : ";
            while(ptr!=NULL){
                cout<<ptr->data<<" ";
                ptr=ptr->next;
            }
            cout<<endl;
        }
        ~LinkedList() {          
            Node *current = Head;
            while (current != NULL) {
                Node *next = current->next;
                delete current;
                current = next;
            }
        }
};

int main(){    
    int choice,value,key;     
    LinkedList list;          


    do{
        cout << "_______LINKED LIST OPERATIONS _______" << endl;
        cout << "1. Insert Element at Begining" << endl;
        cout << "2. Search Element" << endl;
        cout << "3. Delete Node by Value" << endl;
        cout << "4. Reverse Linked List " << endl;
        cout << "5. Display linked list" << endl;
        cout << "6. Exit " << endl << endl;
        cout<<"Enter your choice : ";
        cin>>choice;       

        switch(choice){         
            case 1:{    
                cout << endl;     
                cout << "INSERTION OPERATION" << endl << endl;
                cout<<"Enter the element : ";
                cin>>value;
                list.insertAtBeginning(value);
                cout << endl;
                break;
            }
            case 2:{    
                cout << endl;     
                cout << "SEARCH OPERATION" << endl << endl;            
                if(!list.isEmpty()){         
                    cout<<endl<<"Enter the Value : ";
                    cin>>value;
                
                    list.search(value);
                }
                else{
                    cout<<endl<<"LINKED LIST IS EMPTY"<<endl<<endl;
                }
                cout << endl;
                break;
            }
            case 3:{ 
                cout << endl;         
                cout << "DELETE OPERATION" << endl << endl;
                if(!list.isEmpty()){         
                    cout<<endl<<"Enter the value you want to delete : ";
                    cin>>value;
                    list.deleteNode(value);
                }
                else{
                    cout<<endl<<"LINKED LIST IS EMPTY"<<endl<<endl;
                }
                cout << endl;                
                break;
            }
            case 4:{ 
                cout << endl;        
                cout << "REVERSE OPERATION" << endl << endl;
                if(!list.isEmpty()){         
                    list.reverse();
                }
                else{
                    cout<<endl<<"LINKED LIST IS EMPTY"<<endl<<endl;
                }
                cout << endl;
                break;
            }
            case 5:{ 
                cout << endl;         
                cout << "DISPLAY OPERATION" << endl << endl;
                if(!list.isEmpty()){         
                    list.display();
                }
                else{
                    cout<<endl<<"LINKED LIST IS EMPTY"<<endl<<endl;
                }
                cout << endl;
                break;
            }
            case 6:{ 
                cout << endl;             
                cout << "THANKYOU FOR PERFORMING LINKED LIST OPERATIONS" << endl;
                break;
            }
            default:{            
                cout<<endl<<"INVALID CHOICE"<<endl;
                break;
            }
        }
    }
    while(choice!=6);

    return 0;
}