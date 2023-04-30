#include<iostream>
using namespace std;
int main(){
    int x,y;
    cout << "2つの整数値を入力して下さい:";
    cin >> x >> y;

    int ave = (x + y) / 2;
    double Ave = (x + y) / 2.0;

    cout << ave << endl;
    cout << Ave << endl;
}
