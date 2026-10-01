#include <iostream>
#include <string>

using namespace std;

struct Node {
    string data;
    Node* prev;
    Node* next;
};

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;

    string command;

    while (true) {
        cin >> command;

        if (command == "add_front") {
            string title;
            cin >> title;

            Node* newNode = new Node{title, nullptr, nullptr};

            if(head == nullptr){
                head = newNode;
                tail = newNode;
            }
            else if(head!= nullptr){
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }

            cout<<"ok\n";
        }

        else if (command == "add_back") {
            string title;
            cin >> title;

            Node* newNode = new Node{title, nullptr, nullptr};
            if(head == nullptr){
                head = newNode;
                tail = newNode;
            }
            else{
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }

            cout<<"ok\n";
        }

        else if (command == "erase_front") {
            if(head == nullptr){
                cout<<"error\n";
            }
            else if(head == tail){

                cout << head->data << "\n";
                delete head;

                head = nullptr;
                tail = nullptr;
                
                
            }
            else{
                cout << head->data << "\n";

                Node* temp = head;
                head = head->next;
                head->prev = nullptr;
        
                delete temp;

            }
        }

        else if (command == "erase_back") {
            if(head == nullptr){
                cout<<"error\n";
            }
            else if(head== tail){
                cout<<head->data<<"\n";
                delete head;
                head= nullptr;
                tail = nullptr;
            }
            else{
                cout<<tail->data<<"\n";
                Node* temp = tail;
                tail = tail->prev;
                tail->next = nullptr;
                delete temp;
            }
        }

        else if (command == "front") {
            if (head == nullptr) {
                cout << "error\n";
            }
            else {
                cout << head->data << "\n";
            }
        }

        else if (command == "back") {
            if (tail == nullptr) {
                cout << "error\n";
            }
            else {
                cout << tail->data << "\n";
            }
        }

        else if (command == "clear") {
            while(head != nullptr){
                Node* temp = head;
                head = head->next;
                delete temp;
            }
            tail = nullptr;
            cout << "ok\n";
        }

        else if (command == "exit") {
            cout << "goodbye";
            break;
        }
    }

    return 0;
}