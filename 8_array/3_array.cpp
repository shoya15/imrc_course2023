// 要素数が5の配列aの要素を配列bに逆順にコピーするプログラム
#include <iostream>
using namespace std;
int main()
{
    const int n = 5;
    int a[n], b[n] = {0};

    for (int i = 0; i < n; i++)
    {
        cout << "a[" << i << "]:";
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        b[i] = a[n - i - 1]; // i+n-1だとiも更新されておかしくなる
    }

    for (int i = 0; i < n; i++)
    {
        cout << "b[" << i << "]=" << b[i] << endl;
    }
}