//読み込んだ整数値が正であれば偶数/奇数の判別をして表示
//そうでなければエラーを表示
#include<iostream>
using namespace std;
int main()
{
    int n;
    cout << "整数値:";
    cin >> n;

    if(n > 0){
        if(n % 2 == 0)
            cout << "偶数です\n";
        else
            cout << "奇数です\n";
    }
    else
        cout << "error\n";
}
/*
if文の中にif文が入っている-->入れ子構造(ネスト)

if(条件 && 条件 && 条件)条件かつ条件かつ条件
if(条件 || 条件 || 条件)条件または条件または条件
*/
