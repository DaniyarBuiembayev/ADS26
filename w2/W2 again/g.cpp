#include <iostream>
#include <vector>
#include <string>


using namespace std;

struct Node{
    string data;
    Node* next;
};

int main(){

int a,b;
cin>>a>>b;


Node* head = nullptr;
Node* tail = nullptr;

for(int i = 0; i < a; i++){
    string x;
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

Node* current  = head;
for(int i = 1; i < b; i++){
    current = current->next;
}

Node* newHead = current->next;
current->next = nullptr;
tail->next = head;
head = newHead;

current = head;
while(current != nullptr){
    cout<<current->data<<" ";
    current = current->next;
}

    return 0;
}