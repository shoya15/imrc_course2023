// 正の整数値を読みこんで逆から表示するプログラミング
#include<iostream>
using namespace std;
int main(){
int x;

    cout<<"正の整数値を逆にします。\n";
    do{
        cout<<"正の整数値：";
        cin>>x;
    } while (x<=0);
    
    while(x > 1){
        cout<<x % 10;
        x = x / 10;
    }
}