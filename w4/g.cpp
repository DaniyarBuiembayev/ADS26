#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

int main(){

    int n;
    cin>>n;
    vector <int> val;
    vector<int> L,R;
    map<int , int> idx;
    set<int> s;

    for(int i =0 ; i<n; i++){
        int x;
        cin>>x;
        if(s.count(x)){
            continue;
        }
        int id = val.size();
        val.push_back(x);
        L.push_back(-1);
        R.push_back(-1);

        if(!s.empty()){
            auto it = s.lower_bound(x);
            int parent = -1;
            if(it != s.end()){
                parent = idx[*it];
            }
            if(it!=s.begin()){
                int p = idx[*prev(it)];
                parent = max(parent,p);
            }

            if(val[parent] <x){
                R[parent] = id;
        
            }
            else{
                L[parent] = id;
            }
        }
        s.insert(x);
        idx[x] = id;
    }

    int m = val.size();
    vector <int> h(m,0);
    int answer =0;

    for(int i = m -1; i>=0; i--){
        int l = L[i] == -1 ? 0 :h[L[i]];
        int r = R[i] == -1 ? 0 :h[R[i]];
        h[i] = 1 +max(l,r);
        answer = max(answer,l+r+1);
    }
    cout<<answer<<"\n";
}