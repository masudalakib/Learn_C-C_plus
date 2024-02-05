#include<stdio.h>
int main()
{
    int key = 420;
    int a[7]= {1,1,2,4,90,420,1000};
    int low =0, high=6,mid;
    while(low<=high)
    {
          mid =(low+high)/2;
    if(a[mid]==key)
    {
        printf("Found the key index =%d", mid);
        break;
    }
    else if(key>a[mid])
    {
        low=mid+1;
    }
        else if(key<a[mid])
        {
            high=mid-1;
        }
    }



    return 0;
}
