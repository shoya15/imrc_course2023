#include<iostream>
using namespace std;
int main()
{
    int n;

    cout << "整数値:";
    cin >> n;

    if(n > 0)
        cout << "その値は正です。\n";
    else
        cout << "その値は正ではないです。\n";
}

/*
*if文
　ある条件が成立するかどうかによって、行うべき処理を選択的に決定できる
　switch文と合わせて選択文と呼ばれる
・使い方
if(条件)文;

if(条件)文;
else文;

条件の真偽によって異なる処理を行う場合は、else文付きのif文で実行する

・関係演算子
x<y:xがyより小さければtrueを、そうでなければfalseを生成。
x>y:xがyより大きければtrueを、そうでなければfalseを生成。
x<=y:xがyより小さいか等しければtrueを、そうでなければfalseを生成。
x>=y:xがyより大きいか等しければtrueを、そうでなければfalseを生成。

・等価演算子
x==y:xとyが等しければtrueを、そうでなければfalseを生成。（x=yだと代入になる）
x!=y:xとyが等しくなければtrueを、そうでなければfalseを生成。
*/
