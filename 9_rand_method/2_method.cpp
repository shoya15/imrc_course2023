// 四則演算の関数を作って、main関数内で呼び出すプログラム
// 差は正の値で返す
#include <iostream>
using namespace std;
int p(int x, int y)
{
    int p = x + y;
    return p;
}

int q(int x, int y)
{
    int q = x - y;
    if (q < 0)
        q = -q;
    return q;
}

int r(int x, int y)
{
    int r = x * y;
    return r;
}

float s(float x, float y)
{
    float s = x / y;
    return s;
}

int main()
{
    int a, b;
    float c, d;
    cin >> a >> b >> c >> d;
    cout << p(a, b) << endl;
    cout << q(a, b) << endl;
    cout << r(a, b) << endl;
    cout << s(c, d) << endl;
}