// 右下側が直角の（二等辺）三角形を表示
#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"正の整数値を入力して下さい。";
    cin>>n;

     for(int i=0;i<n;i++){
        for(int j=n;j>i+1;j--){
            cout<<" ";
        }
        for(int j=0;j<=i;j++){
            cout<<"*";
        }
        cout<<endl;
    }
}