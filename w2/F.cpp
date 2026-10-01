#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {

    int n;
    cin >> n;

    Node* head1 = nullptr;
    Node* tail1 = nullptr;

    for (int i = 0; i < n; i++) {

        int x;
        cin >> x;

        Node* newNode = new Node{x, nullptr};

        if (head1 == nullptr) {
            head1 = newNode;
            tail1 = newNode;
        }
        else {
            tail1->next = newNode;
            tail1 = newNode;
        }
    }


    int m;
    cin >> m;

    Node* head2 = nullptr;
    Node* tail2 = nullptr;

    for (int i = 0; i < m; i++) {

        int x;
        cin >> x;

        Node* newNode = new Node{x, nullptr};

        if (head2 == nullptr) {
            head2 = newNode;
            tail2 = newNode;
        }
        else {
            tail2->next = newNode;
            tail2 = newNode;
        }
    }


    Node* current1 = head1;
    Node* current2 = head2;

    Node* head = nullptr;
    Node* tail = nullptr;


    while (current1 != nullptr && current2 != nullptr) {

        Node* temp;

        if (current1->data <= current2->data) {
            temp = current1;
            current1 = current1->next;
        }
        else {
            temp = current2;
            current2 = current2->next;
        }

        temp->next = nullptr;

        if (head == nullptr) {
            head = temp;
            tail = temp;
        }
        else {
            tail->next = temp;
            tail = temp;
        }
    }


    if (current1 != nullptr) {
        if (head == nullptr) {
            head = current1;
        }
        else {
            tail->next = current1;
        }
    }
    else {
        if (head == nullptr) {
            head = current2;
        }
        else {
            tail->next = current2;
        }
    }


    Node* current = head;

    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }

    return 0;
}