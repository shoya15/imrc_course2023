// 3で割り切れるならFizz、5で割り切れるならBuzz、両方で割り切れるならFizzBuzzを出力（FizzBuzz問題）
#include <iostream>
using namespace std;
int main()
{
    for( int i=1;i<=100;i++){
        if(i % 3 == 0 && i % 5 == 0){
            cout << i << ": FizzBuzz" << endl; 
        }else if(i % 3 == 0){
            cout << i << ": Fizz" << endl;
        }else if(i % 5 == 0){
            cout << i << ": Buzz" << endl;
        }
    }
}
