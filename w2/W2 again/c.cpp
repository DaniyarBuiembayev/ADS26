#include <iostream>
#include <vector>
#include <string>
#include <vector>


using namespace std;

struct Node{
    string data;
    Node* next;
};

int main(){
    int a;
    cin>>a;

    Node* head = nullptr;
    Node* tail = nullptr;

    for(int i = 0; i<a; i++){
        string x;
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
    Node* current = head;
    int count = a;
    
    while(current != nullptr && current->next != nullptr){
        if(current->data == current->next->data){
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
            count--;
        }
        else{
            current = current->next;
        }
    }

    current = head;
    cout<<count<<"\n";
    
    while(current!= nullptr){
        cout<<current->data<<"\n";
        current = current->next;
    }
    return 0 ;
}