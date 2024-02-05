//Write a program to print X^y. using recursion


#include <iostream>
#include<stdbool.h>
using namespace std;

int power(int x, int y)
 {
    if (y == 0) return 1;
     return x*power(x, y-1);
    }

int main()
{

    int x,y;
    cin>>x>>y;
    cout<<power(x,y)<<endl;
    return 0;
}
