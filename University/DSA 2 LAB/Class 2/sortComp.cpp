#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[]= {9,5,3,1,14,2,20,5};
    int len =sizeof(arr)/sizeof(arr[0]);

    for (int i =0; i<len; i++){

        printf("%d",arr[i]);
        cout<<endl;
    }
    cout << "Ascending order: ";
    sort(arr+2,arr+6);
    for(int i=0; i<len; i++){
        printf("%d",arr[i]);
        printf("\n");

    }

    cout << "Descending order: ";
    sort(arr+2,arr+6, comp<int>());
    for(int i=0; i<len; i++){
        printf("%d",arr[i]);
        printf("\n");

    }


    return 0;
}


