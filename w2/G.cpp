#include <iostream>

using namespace std;

struct Node{
    string data;
    Node* next;
};

int main(){

    int a,c;
    cin>>a>>c;

    Node* head = nullptr;
    Node* tail = nullptr;

    for(int i = 0; i<a;i++){
        string x;
        cin>>x;
        Node* newNode = new Node{x, nullptr};

        if(head==nullptr){
            head = newNode;
            tail = newNode;
        }
        else{
            tail ->next  = newNode;
            tail = newNode;
        }
    }

    Node* current  = head;

    for (int i = 0; i < c - 1; i++) {
        current = current->next;
    }

    Node* newHead = current->next;
    current->next = nullptr;
    tail->next = head;
    head = newHead;

    current = head;

    while (current != nullptr) {
    cout << current->data << " ";
    current = current->next;
}


    return 0;
}