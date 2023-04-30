// おみくじ
#include<iostream>
#include<random>
using namespace std;
int main()
{
    int n;
    cout << "数値を入力して下さい: ";
    cin >> n;

    switch (n){
        case 1:
        case 2: cout<<"大吉\n"; break;
        case 3:
        case 4: cout<<"吉\n"; break;
        case 5:
        case 6: cout<<"中吉\n"; break;
        case 7: cout<<"小吉\n"; break;
        case 8: cout<<"末吉\n"; break;
        case 9: cout<<"凶\n"; break;
        case 10: cout<<"大凶\n"; break;
        default: cout << "正しくない数値が入力されました\n";
    } 
}
