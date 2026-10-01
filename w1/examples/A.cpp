#include <iostream>
using namespace std;

int main(){
    long long a,b;
    cin>>a>>b;

    while(b!=0){
        long long CurNum = a%b;
        a=b;
        b=CurNum;
    }
    cout<<a;
    return 0;
}






