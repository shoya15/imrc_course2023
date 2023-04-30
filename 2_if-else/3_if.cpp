// 2つの整数値の差（絶対値）を表示するプログラム(absメソッドは使わないで下さい)
#include<iostream>
using namespace std;
int main()
{
    int x, y;
    cin >> x >> y;

    if(x - y > 0) // x>yの場合
        cout << x - y << endl;
    else // x<yの場合
        cout << -(x - y) << endl;
}
