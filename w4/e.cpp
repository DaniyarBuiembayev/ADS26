#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    int n;
    cin>>n;

    vector<long long> leftChild(n+1,0);
    vector <long long > rightChild(n+1,0);

    for(int i=0;i<n-1;i++){
        int a,b,c;
        cin>>a>>b>>c;

        if(c==0){
            leftChild[a] = b;
        }
        else{
            rightChild[a] = b;
        }
    }
    queue <long long> q;
    q.push(1);
    int answer = 0;
    while(!q.empty()){
        int levelSize = q.size();
        if(levelSize > answer){
            answer = levelSize;
        }
    
    

    for(int i = 0; i<levelSize; i++){
        int v = q.front();
        q.pop();

        if(leftChild[v]!=0){
            q.push(leftChild[v]);
        }
        if(rightChild[v]!=0){
            q.push(rightChild[v]);
        }
    }
    }
    cout<<answer<<"\n";
    return 0 ;
}
