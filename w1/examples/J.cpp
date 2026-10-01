#include <iostream>
#include <deque>
using namespace std;


bool BorisWins(int a, int b){

    if(a == 0 && b ==9){
        return true;
    }
    if(b==0 && a ==9){
        return false;
    }
    if(a>b){
        return true;
    }
    return false;
}


int main(){

    deque <int> Boris;
    deque <int> Nursik;


    for(int i = 0; i<5; i++){
        int x;
        cin>>x;
        Boris.push_back(x);
    }
    for(int i=0; i<5; i++){
        int x;
        cin>>x;
        Nursik.push_back(x);
    }
    
    int moves = 0;

    while(!Boris.empty() && !Nursik.empty()){

       int a = Boris.front();
       int b = Nursik.front();

        Boris.pop_front();
        Nursik.pop_front();


        if(BorisWins(a,b)){
            Boris.push_back(a);
            Boris.push_back(b);
        }
        else{
            Nursik.push_back(a);
            Nursik.push_back(b);
        }
        moves++;
    }
    if(!Boris.empty()){
        cout<<"Boris " << moves;
    }
    else{
        cout<<"Nursik " << moves;
    }
    return 0;
}