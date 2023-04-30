//読み込んだ整数値を加算（負の値は計算しない）
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
        cout<<"整数：";
        cin>>t;
        if(t<0){
            cout<<"負の値は加算しません。\n";
            continue;
        }
        sum+=t;
    }
    cout<<"合計は"<<sum<<"です。\n";
}

// continue文:ループ本体の残りの部分の実行がスキップされて、プログラムの流れはループ本体の末尾へと一気に飛ぶ。
