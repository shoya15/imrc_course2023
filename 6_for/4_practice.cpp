/*
  *
 ***
*****
n = 3の場合

指定された段数をピラミッドで表示するプログラム
*/
#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"正の整数値を入力して下さい。";
    cin>>n;

     for(int i=1;i<=n;i++){
        for(int j=n;j>i;j--){
            cout<<" ";
        }
        for(int j=1;j<2*i;j++){
            cout<<"*";
        }
        cout<<endl;
    }
}