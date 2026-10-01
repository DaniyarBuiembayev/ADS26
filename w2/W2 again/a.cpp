#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;


int main(){
    int a;
    cin>>a;

    while(a!=0){

        int b;
        cin>>b;

        queue <char> c1;
        int freq[26] = {};


        for(int i = 0;i<b; i++){
            char x;
            cin>>x;

            freq[x-'a']++;

            if(freq[x-'a']==1){
                c1.push(x);
            }

            while(!c1.empty() && freq[c1.front() - 'a'] > 1){
                c1.pop();
            }
            if(c1.empty()){
                cout<<-1<<" ";
            }
            else{
                cout<<c1.front()<<" ";
            }

        }
        a--;
        cout<<"\n";
    }
    return 0;
}