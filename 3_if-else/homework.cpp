// 100以下の整数Nが与えられる。N以下の整数のうち、7を含むものはいくつあるかを求めるプログラム
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;

    int q = n / 10;
    int m = n % 10;
    int ans = q;
    if(q == 7) ans += m + 1;
    if(7 <= m) ans += 1;
    if(80 <= n) ans += 9;
    cout << ans << endl;
}
