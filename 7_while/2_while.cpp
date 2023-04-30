#include<iostream>
using namespace std;
int main(){
    int x;

    cout<<"カウントダウンします。\n";
    do{
        cout<<"正の整数値：";
        cin>>x;
    } while (x<=0);
    // x<=0を入れるとやり直しを要求される

    while(x>=0){
        cout<<x<<endl;
        x--;
    }
}
/*
・while文
・使い方
while(条件)文;
条件を満たしている間、中の文を繰り返し実行する（ループする）
*/
