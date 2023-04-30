#include<ctime>
#include<cstdlib>
#include<iostream>
using namespace std;
int main()
{
    srand(time(NULL));

    int lucky = rand()%10;

    switch(lucky){
        case 0:
        case 1: cout<<"大吉です"; break;
        case 2:
        case 3: cout<<"吉です"; break;
        case 4:
        case 5: cout<<"中吉です"; break;
        case 6: cout<<"小吉です"; break;
        case 7: cout<<"末吉です"; break;
        case 8: cout<<"凶です"; break;
        case 9: cout<<"大凶です"; break;
    }
}