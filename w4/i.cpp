#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* insert(Node* root , int value){
    Node* newNode = new Node{value, nullptr, nullptr};

    if(root == nullptr){
        return newNode;
    }

    Node* current = root;

    while(true){
        if(value <= current->data){
            if(current->left == nullptr){
                current->left = newNode;
                break;
            }
            current = current->left;
        }
        else{
            if(current->right == nullptr){
                current->right = newNode;
                break;
            }
            current = current->right;
        }
    }
    return root;
}

int countLeaves(Node* node){
    if(node == nullptr) return 0;
    if(node->left == nullptr && node->right == nullptr) return 1;
    return countLeaves(node->left) + countLeaves(node->right);
}

int main(){
    int n;
    cin >> n;
    Node* root = nullptr;

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        root = insert(root, x);
    }

    cout << countLeaves(root) << '\n';
    return 0;
}