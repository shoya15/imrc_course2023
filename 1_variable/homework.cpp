// 三角形の面積を出力
// 底辺と高さを入力してもらう
#include<iostream>
using namespace std;
int main()
{
    double x,y;

    cout << "底辺の値は:";
    cin >> x;
    cout << "高さの値は";
    cin >> y;

    cout << "三角形の面積は" << (x * y) / 2.0 << endl;
}
