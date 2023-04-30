#include<iostream>
using namespace std;
int main()
{
    int x, y;

    cout << "xの値は:";
    cin >> x; // xに整数値を読み込む（入力）
    cout << "yの値は";
    cin >> y; // yに整数値を読み込む（入力）

    cout << "x+y=" << x + y << endl; // 和を表示
    cout << "x-y=" << x - y << endl; // 差を表示
    cout << "x*y=" << x * y << endl; // 積を表示
    cout << "x/y=" << x / y << endl; // 商を表示
    cout << "x%y=" << x % y << endl; // 余剰を表示（整数型のみ）
}
