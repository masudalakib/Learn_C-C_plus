#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> list2={1,10,200};
    vector<int> list4;
    int x;
    for (int i=0; i<5;i++)
    {

        cin>>x;
        list4.push_back(x);
    }
    printf("size:%d\n", list4.size());

    for (int i=0; i<list4.size(); i++)
        printf("[%d]%d\n", i,list4[i]);

    int i =2;
    list4.erase(list4.begin()+ i);
    for (int x: list4)
        printf("%d\n",x);




}
