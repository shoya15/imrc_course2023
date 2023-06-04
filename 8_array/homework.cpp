// 二次元配列cを宣言（行3、列2）c={(1,2),(3,4),(5,6)}
// 配列cを2倍させて配列を表示するプログラム
#include <iostream>
using namespace std;
int main()
{
    int c[3][2], n, m = 1;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            n = m * 2;
            c[i][j] = n;
            m++;
            cout << "c[" << i + 1 << "][" << j + 1 << "]:" << c[i][j] << endl;
        }
    }
}

/*
int c[3][2]={{1,2},{3,4},{5,6}};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++){
            cout<<2*c[i][j]<<endl;
        }
    }
*/