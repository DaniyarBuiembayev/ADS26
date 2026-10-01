#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
};

int main(){

    Node* head = nullptr;
    Node* tail = nullptr;
    
    if(command == "add_front"){
        string x;
        cin>>x;

        Node* newNode = new Node{x, next, prev};
    }
    else if (command == "add_back"){

    }
    else if(command =="erase_front"){

    }
    else if(command == "erase_back"){

    }
    else if(command =="front"){

    }
    else if(command =="back"){

    }
    else if(command =="clear"){

    }
    else if(command =="exit"){

    }
    return 0;
}