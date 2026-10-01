#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n,m;
    cin>>n,m;


    vector<int> end(n);
    int sum = 0;


    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
    
        sum += x;
        end[i] = sum;
    }

    while(q--){
        int mistake;
        cin>>mistake;

        int finding = lower_bound(end.begin(); end.end(), mistake) - end.begin();
        cout<<finding+1<<"\n";
    }


    return 0; 
}