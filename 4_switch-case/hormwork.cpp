/*
指定した月の季節を表示するプログラム(switch文)
ただし、3~4:春、6~8:夏、9~11:秋、12,1,2:冬とする
*/
#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"何月ですか？(数値を入力してください):";
    cin>>n;

    switch(n){
        case 3 :
        case 4 :
        case 5 : cout<<"春\n"; break;
        case 6 :
        case 7 :
        case 8 : cout<<"夏\n"; break;
        case 9 : 
        case 10 :
        case 11 : cout<<"秋\n"; break;
        case 12 :
        case 1 : 
        case 2 : cout<<"冬\n"; break;
        default: cout<<"正しくない数値が入力されました。\n"; break;
    }
}
