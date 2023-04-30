#include <iostream>
using namespace std;
int main()
{
    int m[2][3];

    cout << "各構成要素の値を入力してください" << endl;
    // 入力
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << "m[" << i << "][" << j << "]:";
            cin >> m[i][j];
        }
    }
    cout << endl;
    // 出力
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << "m[" << i << "][" << j << "]=" << m[i][j] << endl;
        }
    }
}
/*
・多次元配列：配列を要素とする配列。（2次元以上の配列の総称）

a[i]：配列の要素
a[i][j]：配列aの構成要素

配列の要素数
行数=sizeof(a)/sizeof(a[0])   6/3=2
列数=sizeof(a[0])/sizeof(a[0][0])   3/1=3
*/