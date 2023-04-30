// cf) 3_switch.cpp

#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
int main(){
    int check=1;
    
    do{
        srand(time(NULL));
        int lucky=rand()%10;
        cout<<"本日のラッキーナンバーは"<<lucky<<"です。\n";
        cout<<"続けますか? Yes->0 / No->1\n";
        cin>>check;
    } while (check==0);

    cout<<"end\n";
}
/*
・do(-while)文
・使い方
do{
    文;
} while(条件);

doとwhileに囲まれた文が条件を満たしている限り、繰り返し続ける。

・while文とfor文の異なる点
必ず1回do-whileの中が実行される。
*/
