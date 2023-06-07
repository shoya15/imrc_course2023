// 3つの値の最小値を求める関数を作成する。
#include <iostream>
#include <algorithm>
using namespace std;
int m(int x, int y, int z)
{
    int m = min({x, y, z});
    // int m = min(x, min(y, z));
    return m;
}

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    cout << "3つの値の最小値は" << m(a, b, c) << "です。\n";
}