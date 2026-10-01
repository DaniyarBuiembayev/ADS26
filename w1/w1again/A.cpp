#include <iostream>
using namespace std;


int main(){
    long long a,b;
    cin>>a>>b;

    while(b!=0){
        long long result = a%b;
        a=b;
        b=result;
    }
    cout<<a;
    return 0;
}