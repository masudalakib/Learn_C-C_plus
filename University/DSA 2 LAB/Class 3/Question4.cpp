#include<iostream>
using namespace std;
int power(int x, int y)
{
    if(y==1) return x;

    int p=power(x,y/2);
    if(y%2==0)
        return p*p;
        else return p*p*x;
}



int main() {

   int x,y;
   cin>>x;
   cin>>y;

   cout << power(x,y);

    return 0;
}
