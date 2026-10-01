#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
};

int main(){
    int a;
    cin>>a;

    if(a==1){
        return 0;
    }
    int value;
    cin>>value;
    Node* head = new Node{value, nullptr};
    Node* current = head;
    
    Node* slow = head;
    Node* fast = head;
    Node* superSlow = nullptr;

    while(a>1){
        cin>>value;
        Node* newNode = new Node{value, nullptr};
        current ->next = newNode;
        current = newNode;
        a--;
    }

    while(fast!= nullptr && fast -> next != nullptr){
        superSlow = slow;
        slow = slow ->next;
        fast = fast->next->next;
    }
    superSlow->next = slow ->next;

current = head;
    while(current != nullptr){
        cout<<current->data;
        if(current ->next != nullptr){
            cout<<" ";
        }
        current = current ->next;
    }
    cout<<endl;
    return 0;


}