#include <iostream>
#include <vector>

using namespace std;

int main(){

    int a;
    cin>>a;

    vector<int> b(a);

    for(int i =0;i<a;i++){
        cin>>b[i];
    }

    int x;
    cin>>x;

    int left = 0;
    int right = a - 1;


    while(left<= right){
        int mid = (left+right) /2;
        if(b[mid] == x){
            cout<<"Yes";
            return 0;
        }
        else if(b[mid] <x){
            left = mid+1;
        }
        else{
            right = mid-1;
        }

    }
    cout << "No";
    return 0;
}