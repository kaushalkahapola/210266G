#include <iostream>
#include <vector>
using namespace std;

double findmedian(int arr[], int size){
    double median;
    if(size % 2 == 0){
        median = (arr[size/2] + arr[(size/2)-1])/2.0;
    }
    else{
        median = arr[size/2];
    }
    return median;
}

void addnum(int*& arr, int num, int size){
    int *newarr = new int[size+1];
    int i=0,j=0;
    while(i<size & j<size+1){
        if(num<arr[i] & i==j){
            newarr[j]=num;
            num=arr[size-1];
            j++;
        }
        else{
            newarr[j]=arr[i];
            if(i==size-1){
            newarr[size]=num;
            break;
            }
            i++;
            j++;
        }
    }

    delete[] arr;
    arr = newarr;
}


int main(){
    int size;
    cout<<"Enter the size of the array: ";
    cin>>size;
    int elements[size];
    for(int i=0;i<size;i++){
        cin>>elements[i];
    }
    for(int i=0;i<size;i++){
        cout<<elements[i]<<" ";
    }
    cout<<endl;
    int* arr = new int[1]{elements[0]};
    
    for(int i=0;i<size;i++){
        cout<<findmedian(arr,i+1)<<" [ ";
        for(int j=0;j<=i;j++){
        cout<<arr[j]<<" ";
        }
        cout<<"]"<<endl;
        addnum(arr,elements[i+1],i+1);
        }
    delete[] arr;
return 0;
}
