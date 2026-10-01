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
    cin>>n;

    if(n <= 1){
        return 0;
    }
    
    Node* head =nullptr;
    Node* tail = nullptr;
    Node* slow = nullptr;
    Node* fast = nullptr;
    Node* prev = nullptr;

    for(int i=0 ; i<n; i++){

        int x;
        cin>>x;

        Node* newNode = new Node{x,nullptr};
        
        if(head == nullptr){
            head = newNode;
            tail = newNode;

        }
        else{
            tail ->next = newNode;
            tail = newNode;
        }
    }
    slow = head;
    fast = head;

    while(fast != nullptr && fast->next != nullptr){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = slow->next;
    delete slow;

    fast = head;
    while(fast!=nullptr){
        cout<<fast->data<<" ";
        fast = fast->next;
    }
    return 0;
}