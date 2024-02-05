#include<stdio.h>
int main()
{
    int a[]={32,5,80,123, 1, 9, 45};
    int i,j, min_index;
     //outer loop to iterate over all the number
    for(i=0; i<7;i++){
        min_index =i;
        //inner loop to find the minimum intex
    for ( j = i+1; j < 7; j++)
    {
        if(a[j]< a[min_index])
        min_index = j;
    }
    
     //swap
    int temp = a[i];
    a[i]= a[min_index];
    a[min_index]=temp;
    }

   //print the sorted array
   for (i=0; i<7;i++){
    printf("%d ", a[i]);
   }
    printf("\n \n");

    return 0;
}