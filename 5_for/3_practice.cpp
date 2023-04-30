// 指定した正の整数値から0までカウントダウンするプログラム
#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"正の整数値を入力して下さい。";
    cin>>n;

    for(int i=n;i>=0;i--){
        cout<<i<<endl;
    }
}
