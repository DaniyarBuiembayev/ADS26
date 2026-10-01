#include <iostream>
using namespace std;
#include <string>

string process(string s){

    string result;

    for(char c : s){
        if(c == '#'){
            if(!result.empty()){
                result.pop_back();
            }
        }
        else{
            result.push_back(c);
        }
    }
    return result;
}

int main(){

    string s1,s2;
    cin>>s1>>s2;
    
    if(process(s1)==process(s2)){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
    
    return 0;
}