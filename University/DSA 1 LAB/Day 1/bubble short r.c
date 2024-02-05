#include<stdio.h>
int main()
{
    int a[4]= {5,1,2,6};
    for(int j=0; j<4; j++)
    {

        int min = a[j], min_index=j;
        for(int i=j+1; i<4; i++)
        {
            if(a[i]<min)
            {
                min=a[i];
                min_index=i;
            }
        }
        int temp = a[j];
        a[j] = a[min_index];
        a[min_index] = temp;
    }

    for(int j=0; j<4; j++)
    {
        printf("%d ", a[j]);
    }
        //printf("min = %d min_index = %d", min,min_index);
        return 0;
    }

