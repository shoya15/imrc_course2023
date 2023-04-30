//読み込んだ整数値を加算（0で強制終了）
#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"整数を加算します。\n何個加算しますか。:";
    cin>>n;

    int sum=0;
    for(int i=0;i<n;i++){
        int t;
        cout<<"整数(0で強制終了):";
        cin>>t;
        if(t==0)
            goto Exit;
        sum+=t;
    }
    cout<<"合計は"<<sum<<"です。\n";

    Exit: cout << "exit\n";
}

/*
goto文:プログラムの流れは指定されたラベルへと一気に飛ぶ。

・使い方
    goto ラベル;
    ラベル : 文 ;
*/
