#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"整数を入力してください：";
    cin>>n;

    switch(n){
        case 0: cout<<"A";
                cout<<"B"; break;
        case 2: cout<<"C";
        case 5: cout<<"D"; break;
        case 6:
        case 7: cout<<"F"; break;
        default: cout<<"F"; break;
    }
    cout<<endl;
}