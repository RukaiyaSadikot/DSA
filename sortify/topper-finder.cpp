#include <iostream>
using namespace std;
// finding largest and second largest elements in the array
int main() {
    
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

    int largest = 0, second = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] > largest) {
            second = largest;
            largest = arr[i];
        } else if (arr[i] >= second) {
            second = arr[i];
        }
    }

    cout << "Largest: " << largest << endl;
    cout << "Second Largest: " << second << endl;

    return 0;
}