#include <iostream>
#include <stack>

using namespace std;

int main(){

    string x;
    cin>>x;

    stack < char > first;

    for (int i = 0 ; i<x.size();i++){
        if(first.empty() || first.top() != x[i]){

            first.push(x[i]);
        }
        else{
            first.pop();
        }
    }

    if(first.empty()){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    return 0;
}