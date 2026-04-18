#include<iostream>
using namespace std;
// counting positive and negative numbersin an array
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

    int positive = 0, negative = 0;

    for(int i = 0; i < size; i++){
        if ( arr[i] >= 0){
            positive++;
        }else{
            negative++;
        }
    }

    cout << " Total no. of Positive numbers in given array are " << positive << endl;
    cout << " Total no. of Negative numbers in given array are " << negative << endl;

    return 0;
}