// 読み込んだ個数だけ*を表示させるプログラム
#include<iostream>
using namespace std;
int main(){
    int n;

   cout<<"整数値を入力してください";

    do{
        cin>>n;
    }while(n<=0);

    while(n>=1){
        // cout<<"*"<<endl; 
        cout<<"*";
        // endlが改行：つければ縦になるし、つけなければ横になる
        n--;
    }
    // cout<<endl;で改行作れる
    // doは抜けて、繰り返されるからアスタリスク個数分出る
}