#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <deque>

using namespace std;

bool Boris(int a, int b){
    if(a == 0 && b==9){
        return true;
    }
    if(b==0 && a==9){
        return false;
    }
    if(a>b){
        return true;
    }
    return false;
}
int main(){

    deque < int > borya;
    deque < int > nursik;

    for(int i = 0; i<5; i++){
        int x;
        cin>>x;
        borya.push_back(x);
    }

    for(int i = 0; i<5; i++){
        int x;
        cin>>x;
        nursik.push_back(x);
    }

    int moves = 0 ;

    while(!borya.empty() && !nursik.empty()){
        int a = borya.front();
        int b = nursik.front();

        borya.pop_front();
        nursik.pop_front();

        if(Boris(a,b)){
            borya.push_back(a);
            borya.push_back(b);
        }
        else{
            nursik.push_back(a);
            nursik.push_back(b);
        }
        moves++;
    }
    if(borya.empty()){
        cout<<"Nursik "<<moves;
    }
    else{
        cout<<"Borya "<<moves;
    }
}


