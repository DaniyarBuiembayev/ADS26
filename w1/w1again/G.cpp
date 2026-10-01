#include <iostream>
#include <stack>
using namespace std;

int main(){

    string a;
    cin>>a;

    stack < char > s1;
    for(int i = 0; i<a.size(); i++){
        if(s1.empty() || s1.top() != a[i]){
            s1.push(a[i]);
        }
        else{
            s1.pop();
        }
    }
    if(s1.empty()){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
    return 0;
}

