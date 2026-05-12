#include<iostream>
using namespace std;

void insertArray(int arr[], int n){              
    for(int i=0; i<n; i++){
        cout<<"arr["<<i<<"] : ";
        cin>>arr[i];
    }
}

int partition(int arr[], int low, int high){
    int pivot = arr[low];   
    int i = low + 1;
    int j = high;
    while(true){
        while(i <= high && arr[i] <= pivot){           
            i++;
        }

        while(arr[j] > pivot){                 
            j--;
        }

        if(i < j){
            swap(arr[i], arr[j]);
        }
        else{   
            break;
        }
    }
    swap(arr[low], arr[j]);
    return j;
}

void quickSort(int arr[], int low, int high){
    if(low>=high){
        return;
    }
    int partitionIndex=partition(arr,low,high);
    quickSort(arr, low, partitionIndex-1);
    quickSort(arr, partitionIndex+1, high);
}

void displayArray(int arr[], int n){            
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}

int main(){           
    int size;

    cout<<"* * * * * QUICK SORTING * * * * *"<<endl;

    cout<<"Enter size of array : ";
    cin>>size;          

    int arr[size];

    cout<<endl<<"Enter array elements : "<<endl;
    insertArray(arr,size);       

    quickSort(arr,0,size-1);     

    cout<<endl<<"Array elements after sorting : ";
    displayArray(arr,size);      
    cout << endl;
    return 0;
}