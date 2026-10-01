#include <iostream>
#include <vector>
#include <string>


using namespace std;

struct Node{
    int data;
    Node* next;
};

int main(){
    int a;
    cin>>a;


    Node* head = nullptr;
    Node* tail = nullptr;

    for(int i = 0; i<a; i++){
        int x;
        cin>>x; 

        Node* newNode = new Node{x, nullptr};

        if(head == nullptr){
            head = newNode;
            tail = newNode;
        }
        else{
            tail ->next = newNode;
            tail = newNode;
        }
    }

    Node *prev = nullptr;
    Node* current = head;
    Node* next ;

    while(current!=nullptr){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    current = head;

    while(current!= nullptr){
        cout<<current->data<<" ";
        current = current->next;
    }
    return 0; 



}