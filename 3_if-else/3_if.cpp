//読み込んだ月の季節を表示するプログラム

/*
if(条件 && 条件 && 条件)条件かつ条件かつ条件
if(条件 || 条件 || 条件)条件または条件または条件
*/
#include<iostream>
using namespace std;
int main()
{
    int month;
    cout<<"月を入力してください：";
    cin>>month;

    if(month>=3 && month<=5)
        cout<<"春です。\n";
    else if(month>=6 && month<=8)
        cout<<"夏です。\n";
    else if(month>=9 && month<=11)
        cout<<"秋です。\n";
    else if(month==1 || month==2 || month==12)
        cout<<"冬です。\n";
    else
        cout<<"エラーです。\n";
}
