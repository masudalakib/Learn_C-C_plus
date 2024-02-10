#include<iostream>
using namespace std;

int sumOfArr(int arr[], int size){
    if(size==0){
        return 0;
    }
    else{
        return arr[size-1]+sumOfArr(arr,size-1);
    }

}


int main(){
    int arr[]={1,4,2,7,2,3,9};

    int size= sizeof(arr)/sizeof(arr[0]);

    cout<<"arrsum:"<<sumOfArr(arr,size);


}