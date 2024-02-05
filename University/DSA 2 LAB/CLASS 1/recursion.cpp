//Write a program to calculate the sum of first n number (1+2+3+4----+n) using regcursion.

#include <iostream>
#include<stdbool.h>
using namespace std;

int sum(int n)
{

    if(n==1) return 1;
    else return n+sum(n-1);

}
int main()
{

    int n;
    scanf("%d", &n);
    //if(IsPrime(n)) printf("prime\n");
    //else printf("not prime\n");
    printf("%d\n", sum(n));
    return 0;
}
