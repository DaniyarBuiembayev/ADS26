#include <iostream>
#include <vector>
#include <algorightm>

using namespace std;

int countRange(const vector<int> &a, int l, int r){
    int left = lower_bound(a.begin(), a.end() , l) - a.begin(); 
    int right = upper_bound(a.begin() , a.end() , r) -a.begin();
    return right -left;
}

int main(){
    int n,q;
    cin>>n>>q;
    
    vector<int> a(n);

    for(int i=0; i <n; i++){
        cin>>a[i];
    }

    sort(a.begin(), a.end());

    while(q--){
        int l1,r1,l2,r2;
        cin>>l1>>r1>>l2>>r2;

        int answer = countRange(a, l1,r1) + countRange(a,l2,r2);
        int left = max(l1,l2);
        int right = min(r1,r2);

        if(left<=right){
            answer -= countRange (a, left, right);
        }
        cout<<answer<<"\n";
    }
    return 0 ;
}