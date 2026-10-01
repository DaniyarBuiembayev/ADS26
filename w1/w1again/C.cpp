#include <iostream>
using namespace std;

int main(){
long long a ;
cin>>a;

bool isPrime = true;
for(long long i = 2; i*i<= a; i++){
    if(a%i==0){
        isPrime = false;
        break;
    }
}

if(isPrime){
    cout<<"YES";
}

else{
    cout<<"NO";
}

}