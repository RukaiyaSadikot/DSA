
#include<iostream>
using namespace std;

int main(){      
    
    int size,search,index;
    bool found=false;

    cout<<"Enter the size of Array : ";
    cin>>size;           

    int arr[size];
    cout<<endl<<"Enter elements in Array : "<<endl;
    for(int i=0; i<size; i++){
        cout<<"arr["<<i<<"] = ";
        cin>>arr[i];      
    }
    cout << endl;

    cout << "Enter element you want to search : ";
    cin >> search;          
    cout << endl;

    for(int i=0; i<size; i++){
        if(arr[i]==search){     
            found=true;
            index=i;
            break;
        }
    }

    if(found){
        cout << "Position of element   : " << index <<" Index";
        cout<<endl<<"Number of comparisons : "<< index + 1 << " Comparisons" << endl;
    }
    else{
        cout << "No Element Found in Array"<< endl;
        cout << "Number of comparisons : " << size <<" Comparisons"<<endl;
    }

    return 0;
}