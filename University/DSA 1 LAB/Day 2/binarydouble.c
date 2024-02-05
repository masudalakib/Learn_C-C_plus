#include<stdio.h>
int main()
{
    int key = 2;
    int save =-1;
    int a[7]= {1,2,2,2,420,2,1000};
    int low =0, high=6,mid;
    while(low<=high)
    {
          mid =(low+high)/2;
    if(a[mid]==key)
    {
      save =mid;
      low =mid+1;  //1st index: high=mid-1;
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


  printf("Found the key index =%d", save);
    return 0;
}
