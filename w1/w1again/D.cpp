#include <iostream>
using namespace std;

int main(){

    long long a;
    cin>>a;

    long long CurNum = 2;

    while(a!=0){
        bool isPrime = true;
        for(long long i = 2; i*i <= CurNum; i++){
            if(CurNum%i ==0 ){
                isPrime = false;
                break;
            }
        }

        if(isPrime){
            a--;
        }
        CurNum++;

    }
    cout<<CurNum-1;
}