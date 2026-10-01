#include <iostream>
#include <queue>

using namespace std;

int main(){
    int a;
    cin>>a;

    while(a!=0){
        int b;
        cin>>b;

        queue <char> q1;

        int freq[26] = {};
        
        for(int i = 0; i<b; i++){
            char c1;
            cin>>c1;
            freq[c1 - 'a']++;

            if(freq[c1 - 'a']==1 ){
                q1.push(c1);
            }
            while(!q1.empty() && freq[q1.front() - 'a'] > 1){
                q1.pop();
            }
            if(!q1.empty()){
                cout<<-1<<" ";
            }
            else{
                cout<<q1.front()<<" ";
            }
        }
        a--;
        cout<<"\n";
    }
    return 0;
}