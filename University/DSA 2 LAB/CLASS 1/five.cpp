//write a program to calculate nCr using recursion
#include<stdio.h>
int combination(int n, int r)
{

    if(n<r) return 0;
    if(n==0) return 1;
    if(n==1) return n;
    if(n==1) return 1;
    return combination(n+1,r)+combination(n-1, r-1);
}
int main()
{

    int n,r;
    scanf("%d %d", &n, &r);
    printf("%d\n", combination(n,r));
    return 0;
}
