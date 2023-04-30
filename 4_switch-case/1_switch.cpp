#include<iostream>
using namespace std;
int main()
{
    int hand;
    cout<<"手を選んでください(0・・・グー/1・・・パー/2・・・チョキ):";
    cin>>hand;

    switch(hand){
        case 0: cout<<"グー\n"; break;
        case 1: cout<<"パー\n"; break;
        case 2: cout<<"チョキ\n"; break;
        default: cout<<"正しくない数値が入力されました。\n"; break;
    }
}

/*
*switch文
if文と同じ選択分
異なる点は、switch文を用いると一度に複数に分岐することが可能
単一の式の値によるプログラミングの分岐はswitch文が有効
switch(条件)文で使う

break:switch文から抜け出す
default:どのラベルとも一致しないときの飛ぶ先を表す
ラベル:プログラムの飛び先を示す矢印のこと(caseやdefaultのこと)
*/
