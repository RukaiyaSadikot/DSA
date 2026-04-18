#include<iostream>
using namespace std;
// sorting array is ascending and descending order
int main(){

    int size;
    int choice;

    cout << "Enter the size of Array : ";
    cin >> size;
    int arr[size];
    cout << "Enter Array elements" << endl;
    for(int i=0; i < size; i++){
        cout << " index[" << i << "] : ";
        cin >> arr[i];
    }
    cout << "Array elements are : " ;
    for(int i=0; i < size ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;    
    do{
        cout << " ---- Sort Menu ---- " << endl;
        cout << " 1. Acending Array sorting...." << endl;
        cout << " 2. Descending Arry Sorting...." << endl;
        cout << " 0. Exit..." << endl;
        cout << " Enter Choice : ";
        cin >> choice;
        switch(choice){
            case 1:
                cout << "\nSorted Array : ";
                for(int i = 0; i < size; i++){
                    for(int j = 0; j < size - 1 - i; j++){
                        if(arr[j] > arr[j + 1]){
                            int temp = arr[j];
                            arr[j] = arr[j + 1];
                            arr[j + 1] = temp;
                        }
                    }
                }
                for(int i = 0; i < size; i++){
                    cout << arr[i] << " ";
                }
                cout << endl;
                break;
            case 2: 
                cout << "\nSorted Array : ";
                for(int i = 0; i < size; i++){
                    for(int j = 0; j < size - 1 - i; j++){
                        if(arr[j] < arr[j + 1]){
                            int temp = arr[j];
                            arr[j] = arr[j + 1];
                            arr[j + 1] = temp;
                        }
                    }
                }
                for(int i = 0; i < size; i++){
                    cout << arr[i] << " ";
                }
                cout << endl;
                break;
            case 0:
                cout << " Thankyou for performing sorting operations...." << endl; 
                break;
            default:
                cout << "Invalid Choice .." << endl;
                break;
        }

    }while(choice != 0);

    return 0;

}