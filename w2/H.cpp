#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;


struct Node{
    int data;
    Node* next;
};

int main(){

    int n;
    cin>>n;

    Node* head = nullptr;
    Node* tail = nullptr;

    for(int i=0; i<n; i++){
        int x;
        cin>>x;
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

    int currentSum = current->data;
    int maxSum = current ->data;

    current = current->next;

    while(current!=nullptr){
        currentSum = max(current->data , currentSum + current->data);
        maxSum = max(currentSum, maxSum);
        current = current->next;
    }

    cout<<maxSum;

    return 0;
}