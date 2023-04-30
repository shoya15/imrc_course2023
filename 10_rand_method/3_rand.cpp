// 1_while.cppで使った

//乱数の生成
#include<ctime>
#include<cstdlib>
#include<iostream>
using namespace std;
int main()
{
    srand(time(NULL)); //乱数の種を設定

    int lucky = rand()%10; //%10でrandを10で割った余剰を出す
                           //つまり、0~9のランダムの数がluckyに入れられる

    cout<<"今日のラッキーナンバーは"<<lucky<<"です。\n";
}

/*
rand(:0~(少なくても)32767の乱数を生成

lucky=rand()%10+1
1~10までの乱数を生成
*/

/*
おみくじ
大吉2割、吉2割、中吉2割、小吉1割、末吉1割、凶1割、大凶1割
*/
