#include <iostream>

using namespace std;

int main(){

    int a;
    cin>>a;

    if(a==1){
        cout<<"NO";
        return 0;
    }

bool isPrime = true;
    for(int i = 2; i*i <=a; i++){
        if(a%i == 0 ){
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




