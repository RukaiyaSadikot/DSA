#include<iostream>
using namespace std;
// spliting array in even and odd then sorting even in ascending and odd in descending
int main(){

    int size;
    cout << "Enter the size of Array : ";
    cin >> size;

    int arr[size];
    cout << "Enter Array elements" << endl;
    for(int i = 0; i < size; i++){
        cout << " index[" << i << "] : ";
        cin >> arr[i];
    }

    cout << "Array elements are : ";
    for(int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << endl;

    int evens[size], odds[size];
    int ec = 0, oc = 0;

    for(int i = 0; i < size; i++){
        if(arr[i] % 2 == 0){
            evens[ec] = arr[i];
            ec++;
        }
        else{
            odds[oc] = arr[i];
            oc++;
        }
    }

    for(int i = 0; i < ec - 1; i++){
        for(int j = 0; j < ec - 1 - i; j++){
            if(evens[j] > evens[j+1]){
                int temp = evens[j];
                evens[j] = evens[j+1];
                evens[j+1] = temp;
            }
        }
    }

    for(int i = 0; i < oc - 1; i++){
        for(int j = 0; j < oc - 1 - i; j++){
            if(odds[j] < odds[j+1]){
                int temp = odds[j];
                odds[j] = odds[j+1];
                odds[j+1] = temp;
            }
        }
    }

    cout << "Sorted Array (Evens asc, Odds desc) : ";
    for(int i = 0; i < ec; i++) cout << evens[i] << " ";
    for(int i = 0; i < oc; i++) cout << odds[i] << " ";
    cout << endl;

    return 0;
}