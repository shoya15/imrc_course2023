//読み込んだ整数を加算（0が入力されたら終了）
#include<iostream>
using namespace std;
int main()
{
    int n; //加算する個数
    cout<<"整数を加算します。\n何個加算しますか:";
    cin>>n;

    int sum=0; //合計値
    for(int i=0;i<n;i++){
        int t;
        cout<<"整数(0で終了):";
        cin>>t;

        if(t==0) break; //tが0の時、for文から抜ける
        sum+=t; //合計sumにtの値を足す
    }
    cout<<"合計は"<<sum<<"です。\n";
}

// break文：繰返し文の実行が中断される
