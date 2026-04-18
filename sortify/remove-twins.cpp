#include<iostream>
using namespace std;
// Remove duplicate elements from array
int main(){

    int size;
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

    for (int i = 0; i < size; i++) {
        int temp = 0; 

        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                temp = 1;  
                break;
            }
        }

        if (temp == 0) {
            cout << arr[i] << " ";  
        }
    }

    return 0;
}