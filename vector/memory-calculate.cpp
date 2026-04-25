#include<iostream>
#include<vector>
#include<string>
using namespace std;

template <class T>        
class MemoryCalculate{            
    private:             
        T id;
        string name;
    public:              
        MemoryCalculate(T id, string name){   
            this->id=id;
            this->name=name;
        }
        T getId(){           
            return id;
        }
        string getName(){          
            return name;
        }
        void display(){       
            cout<<"ID = "<<id<<"   NAME = "<<name<<endl;
        }
};

int main(){
    int choice,id;
    string name;
    bool found=false;

    vector<MemoryCalculate<int>> students;

    do{
        cout << endl;
        cout << "  Student Management System  " << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Display All Students" << endl;
        cout << "3. Remove Student by ID" << endl;
        cout << "4. Search Student by ID" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        cout << endl;
        
        switch(choice){
            case 1:{
                cout<<" * * * * * Add a Student * * * * *"<<endl;
                cout<<"Enter Student Id : ";
                cin>>id;     
                cout<<"Enter Student Name : ";
                cin >> name;         
                students.push_back(MemoryCalculate<int>(id,name));      
                cout<<"Student added successfully"<<endl;
                break;
            }

            case 2:{
                if(!students.empty()){          
                    cout<<" * * * * * Student List * * * * * "<<endl;
                    for(int i=0; i<students.size(); i++){
                        students[i].display();       
                    }
                    cout << endl;
                }
                else{      
                    cout<<"Student list is empty"<<endl;
                }
                break;
            }

            case 3:{
                if(!students.empty()){            
                    cout<<" * * * * * Remove Student by ID * * * * *"<<endl;
                    cout<<"ENTER STUDENT ID     : ";
                    cin>>id;        
                    for(int i=0; i<students.size(); i++){
                        if(students[i].getId()==id){       
                            students.erase(students.begin()+i);        
                            cout << "Student Data Removed Successfully" << endl;
                            found=true;
                        }
                    }
                    if(!found){           
                        cout<<"Given Student Id doesn't exist "<<endl;
                    }
                    found=false;
                }
                else{          
                    cout<<"Student list is empty"<<endl;
                }
                break;
            }

    
            case 4:{
                if(!students.empty()){           
                    cout<<" * * * * * Search By ID * * * * *"<<endl;
                    cout<<"Enter student id : ";
                    cin>>id;        
                    for(int i=0; i<students.size(); i++){
                        if(students[i].getId()==id){       
                            cout<<"Student name with "<<id<<" id = "<<students[i].getName()<<endl;  
                            cout << endl;
                            found=true;
                        }
                    }
                    if(!found){           
                        cout<<"Given Student Id doesn't exist "<<endl;
                    }
                    found=false;
                }
                else{           
                    cout<<"Student Record Empty"<<endl;
                }
                break;
            }

            case 0:{
                cout<<"Thankyou for performing Operations";
                break; 
            }

            default:{
                cout<<"Invalid Choice"<<endl; 
                break;
            }
        }
    }
    while(choice!=0);

    return 0;
}