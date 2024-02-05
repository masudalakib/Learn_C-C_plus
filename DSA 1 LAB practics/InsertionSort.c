 #include<stdio.h>
 int main()
 {

    int a[]={4,88,7,3,1,35};
    int i,value,hole;
    for(i=1; i < 6; i++)
    {
         value = a[i];
         hole =i;
        while(hole >0 && a[hole-1]>value){
            a[hole]=a[hole-1];
            hole--;
        }
        a[hole] = value;
    }
    printf("Sorted Array: \n\n");
    for(i=0;i<6;i++){
        printf("%d ", a[i]);
    }
    printf("\n\n");

    return 0;
 }