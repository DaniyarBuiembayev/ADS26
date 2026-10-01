#include <iostream>
#include <vector>
#include <string>


using namespace std;

struct Node{
    int data;
    Node* next;
};

int main(){
    int n;
cin >> n;
if (n == 0) {
    return 0;
}

Node* head = nullptr;
Node* tail = nullptr;

for(int i = 0; i < n; i++){
    int x;
    cin >> x;

    Node* newNode = new Node{x, nullptr};

    if(head == nullptr){
        head = newNode;
        tail = newNode;
    }
    else{
        tail->next = newNode;
        tail = newNode;
    }
}

Node* current = head;

int curSum = current ->data;
int curMax = current ->data;

current = current->next;



while(current != nullptr){
    curSum = max(current->data , curSum + current->data);
    curMax = max(curSum , curMax);
    current  = current ->next;
}
current = head;

cout<<curMax;
    return 0;
}