#include <iostream>
#include <vector>
#include <string>


using namespace std;

struct Node{
    int data;
    Node* next;
};

int main(){
    
    int x;
    cin>>x;

    Node* head1= nullptr;
    Node* head2= nullptr;
    Node* tail1 = nullptr;
    Node* tail2 =nullptr;

    for(int i=0; i<x; i++){
        int a;
        cin>>a;

        Node* newNode = new Node{a,nullptr};

        if(head1==nullptr){
            head1 = newNode;
            tail1 = newNode;
        }
        else{
            tail1 ->next = newNode;
            tail1 = newNode;
        }
    }
     int c;
     cin>>c;

    for(int i=0; i<c; i++){
        int a;
        cin>>a;

        Node* newNode = new Node{a,nullptr};

        if(head2==nullptr){
            head2 = newNode;
            tail2 = newNode;
        }
        else{
            tail2 ->next = newNode;
            tail2 = newNode;
        }
    }

    Node* current1 = head1;
    Node* current2 = head2;

    Node* headOfSorted = nullptr;
    Node* tailOfSorted = nullptr;

    if(head1 == nullptr){
        headOfSorted = head2;
    }
    else if(head2 == nullptr){
        headOfSorted = head1;
    }
    else{


    while(current1 != nullptr && current2 != nullptr){
        if(current1->data < current2->data){
            if(headOfSorted==nullptr){
                headOfSorted= current1;
                tailOfSorted = current1;
                
            }
            else{
                tailOfSorted->next = current1;
                tailOfSorted = current1;
                
            }

            current1 = current1->next;
        }
        else{
            if(headOfSorted==nullptr){
                headOfSorted=current2;
                tailOfSorted = current2;
            }
            else{
                tailOfSorted->next = current2;
                tailOfSorted = current2;
            }
            current2 = current2->next;
        }
    }


    if(current1 != nullptr){
        tailOfSorted->next = current1;
    }
    else{
        tailOfSorted->next = current2;
    }
    }

    Node* current = headOfSorted;

while(current != nullptr){
    cout << current->data << " ";
    current = current->next;
}

    return 0;
}


