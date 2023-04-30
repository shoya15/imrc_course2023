/*
3つの整数の最大値を求める(if, elsif, elseを1回ずつ使って実装して下さい)
maxメソッドは使わないで下さい
*/
#include<iostream>
using namespace std;
int main()
{
    int x, y, z;
    cin >> x >> y >> z;

    if(x > y && x > z)
        cout << "最大値は" << x << "です。\n";
    
    else if (y > z)
        cout << "最大値は" << y << "です。\n";
    else
    cout << "最大値は" << z << "です。\n";
}
