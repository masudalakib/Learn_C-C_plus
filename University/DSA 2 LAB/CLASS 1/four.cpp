#include <bits/stdc++.h>
using namespace std;

int reverseNum(int num, int revNum)
 {

    if (num==0) return revNum;
     revNum = revNum*10;
     revNum += num%10;

    return reverseNum(num/10, revNum);
    }

int main() {
    int n;

    cout << "Enter a number: ";
    cin >> n;
    int m = reverseNum(n,0);


    if (n==m) cout<<" is a palindrome." << endl;

else cout<< " is not a palindrome." << endl;

    return 0;
}
