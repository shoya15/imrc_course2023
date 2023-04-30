// 九九の表を表示するプログラム
#include<iostream>
#include<iomanip>

using namespace std;
int main(){
    for(int i=1;i<=9;i++){
        for(int j=1;j<=9;j++){
            cout<<setw(3)<<i*j;
        }
        cout<<endl;
    }
}

/*
・for文の多重ループ
繰り返しの中で繰り返しを行う。

外側のfor文は行ループ　内側のfor文は列ループ

setwは配置（数時間のスペース）
*/
