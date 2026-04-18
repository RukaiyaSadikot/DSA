#include<iostream>
using namespace std;

int main(){

    int size;
    cout << "Enter the Size of Array : ";
    cin >> size;

    int arr[size];

    cout << "Enter Array Element..." << endl;
    for(int i = 0; i < size; i++){
        cout << "Index of ["<< i <<"] is : ";
        cin >> arr[i];
    }

    cout << "Array Element : ";
    for(int j = 0; j < size; j++){
        cout << arr[j] << " ";
    }

    cout << "Sorted Array : ";
    for(int k = 0; k < size; k++){
        for(int l = 0; l < size - 1 - k; l++){
            if(arr[l] > arr[l + 1]){
                int temp = arr[l];
                arr[l] = arr[l + 1];
                arr[l + 1] = temp;
            }
        }
    }

    for(int n = 0; n < size; n++){
        cout << arr[n] << " ";
    }

    return 0;
}
