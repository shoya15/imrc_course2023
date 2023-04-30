// 配列aの要素を配列bにコピーするプログラム
#include <iostream>
using namespace std;
int main()
{
    const int n = 5;      //変数nを5で初期化
    int a[n], b[n] = {0}; // const入れているから使える、要素全部に0が入っている

    // 配列aに値を入力
    for (int i = 0; i < n; i++)
    {
        cout << "a[" << i << "]:";
        cin >> a[i];
    }
    // コピーする
    for (int i = 0; i < n; i++)
    {
        b[i] = a[i];
    }
    // 配列bの要素を出力
    for (int i = 0; i < n; i++)
    {
        cout << "b[" << i << "]=" << b[i] << endl;
    }
}