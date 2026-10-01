#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int main(){
    int x;  
    cin>>x;

    vector < int > s1(x);

    for (int i=0; i<x; i++){
        cin>>s1[i];
    }

    stack < int > s2;

    for(int i=0; i<x; i++){
        while(!s2.empty() && s2.top() >= s1[i]){
            s2.pop();
        }
        
        if(s2.empty()){
            cout<< -1 <<" ";
        }

        else{
            cout<<s2.top()<<" ";
        }

        s2.push(s1[i]);
    }
    
    return 0;
}

1 
-1 -1 1 5 1