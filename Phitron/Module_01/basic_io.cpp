#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    // a
    // cin >> x >> y; // read korce keyboard theke
    // cout << x <<" "<< y<<"\n"; //print korbe

    // **********
    // char ch;
    // float f;
    // double d;
    // cin >> ch >>f>>d;
    // cout << ch <<" "<<f<<" "<<d<<"\n";

    // string s ="I love BD ";
    // string s2 = "too much";

    // s= s+s2;
    // cout<<s<<"\n";


    // // ***file theke read korbe ***

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout); //output file e create hoye jabe
    // string s;
    // // cin>>s;
    // getline(cin, s);
    // cout<<s<<"\n";
    // // *******


    // ***file input output***

    // ofstream -->  output file stream
    // ifstream -->  input file stream

    ofstream f;
    f.open("1.txt"); //1.txt file open kore print korte cai
    

    ofstream f2;
    f2.open("2.txt");

    f<<"Hello world\n";
    f2<<"Hello Coder\n";
    

    ifstream input;
    input.open("0.txt");
    int x;
    double y,z;
    input >> x>> y >>z;
    cout<<x<<" "<<y<<" "<<z<<"\n";
    
    //kono file porle na nile amra last e ase close kore dibo
    input.close();
    f.close();
    f2.close();


    return 0;
}
