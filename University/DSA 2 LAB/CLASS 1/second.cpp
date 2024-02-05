//write a program to print the sum of digit of positive integer n. using recursion

#include <iostream>
#include<stdbool.h>
using namespace std;

int sumOfDigit(int n)
{

    if(n==0) return 0;
    else return n%10 + sumOfDigit(n/10);

}
int main()
{

    int n;
    scanf("%d", &n);
    //if(IsPrime(n)) printf("prime\n");
    //else printf("not prime\n");
    printf("%d\n", sumOfDigit(n));
    return 0;
}
