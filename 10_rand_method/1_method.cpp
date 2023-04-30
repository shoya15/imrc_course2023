// 3人の数学・英語の最大値を求めて表示するプログラム
#include <iostream>
using namespace std;

// int max(int a, int b, int c); <--関数宣言
// 前方に定義のない関数を呼び出すには、関数宣言が必要

int max(int a, int b, int c)
{
    int max = a;
    if (b > max)
        max = b;
    if (c > max)
        max = c;
    return max;
}

int main()
{
    int math[3], eng[3];
    for (int i = 0; i < 3; i++)
    {
        cout << "[" << i + 1 << "人目]\n";
        cout << "数学：";
        cin >> math[i];
        cout << "英語：";
        cin >> eng[i];
    }

    // 関数を使って、max_mathとmax_engに最大値を入れる（初期化）
    int max_math = max(math[0], math[1], math[2]);
    int max_eng = max(eng[0], eng[1], eng[2]);

    cout << "数学の最高得点は" << max_math << "です。\n";
    cout << "英語の最高得点は" << max_eng << "です。\n";
}
/*
・関数：ひとまとまりの手続きを、1つの「部品」として求めるもの

・関数の定義（作り方）
    返却値の型　関数名（仮引数の宣言）{
        文;
        return 返却値;
    }

・関数の呼び出し（使い方）
    関数名（実引数）

・return文：呼び出し元への返却を行う

・void型
    void put_stars(int n){
        while(n-->0)
        cout<<"+";
    }
    return文はいらない
*/