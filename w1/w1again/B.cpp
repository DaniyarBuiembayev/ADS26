#include <iostream>
using namespace std;

int main(){
    long long a,b,c;
    cin>>a>>b>>c;


    if(c==1){
        cout<<0;
        return 0 ;

    }

    long long result;

    while(b!=0){

        if(b%2==1){
            result  = result * a % c
        }
        a = a*a%c;
        b/=2;
    }
    cout<<result;
}

