#include <iostream>
#include <string> // stringクラスをインクルードする必要がある
using namespace std;
int main()
{
    char c;
    cout << "文字を入力してください：";
    cin >> c;
    string name;
    cout << "名前を入力してください：";
    cin >> name;

    cout << name << "さんが入力した文字は" << c << "です。\n";
}
