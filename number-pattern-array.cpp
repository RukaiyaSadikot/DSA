#include<iostream>
using namespace std;

int main(){

    int arr[5] = {1,2,3,4,5};

    for(int i = 5; i > 0; i--){
        // space
        for(int k = 1; k < i; k++){
            cout << "*" << " ";
        }
        for(int l = 5 - i ; l >= 0 ; l--){
            cout << arr[l] << " ";
        }
        for(int j = 1; j <= 5 - i ; j++){
            cout << arr[j] << " ";
        }
        cout << endl;
    }

    return 0;
}