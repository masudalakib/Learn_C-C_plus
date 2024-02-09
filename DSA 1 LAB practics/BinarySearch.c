#include<stdio.h>
int main()
{
    int a[]={1,3,4,6,7,89,99};
    int item =7;
 
    int low, high, middle;
    low=0;
    high=6;
   while(low<=high)
   {
     middle=(low+high)/2;
    if(a[middle]==item){
        printf("Item found at index: %d\n", middle);
        return 0;
    }
    else if(a[middle]<item){ //lest e ar khuja lagbe na
        low =middle +1;

    }
    else{
        high = middle-1;
    }
   }
   printf("Item not found\n");
    return 0;

}