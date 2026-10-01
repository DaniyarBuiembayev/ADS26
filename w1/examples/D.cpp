#include <iostream>

using namespace std;

int main(){
    int a;
    cin>>a;

    int NumRn = 2;
    while(a!=0){
        bool isprime = true;
        for(int j = 2; j*j <= NumRn; j++){ 
            if(NumRn%j ==0){
                isprime = false;
                break;
            }
        }
        if(isprime){
            a--;
        }

        NumRn++;
    }
    cout<<NumRn-1;
}