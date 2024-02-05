#include<stdio.h>
int main(){
int arr[] ={20,2,-50,1,9};
int i,j,size=5;
int counter =0;
for(int i=0;i<4;i++)
	{
		printf("%d ",arr[i]);
	}
for ( i = 0; i < size-1; i++)
{
    for (j=0; j<size-1-i; j++)
    {
         counter++;
        if(arr[j]>arr[j+1]){
            int temp = arr[j];
            arr[j]=arr[j+1];
            arr[j+1]= temp;
        }
    }
}
printf("\nAfter sorting.\n" );
for ( i = 0; i < size; i++)
{
    printf("%d ", arr[i]);
}
printf("\nTotal loop: %d\n", counter);

    return 0;
}