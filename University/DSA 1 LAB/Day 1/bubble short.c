#include<stdio.h>
int main()
{
    int a[4]= {5,1,2,6};
    for(int j=0; j<4; j++);
    for(int i=0; i<3; i++)
    {
        if(a[i]>a[i+1])
        {
            int temp = a[i];
            a[i] = a[i+1];
            a[i+1] = temp;
        }
    }
    for(int j=0; j<4; j++)
    {
        printf("%d ", a[j]);
    }
        return 0;
    }

