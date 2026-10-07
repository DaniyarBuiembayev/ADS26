#include <iostream>
#include <vector>

using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

int insert(Node*& root, int value){
    Node* newNode = new Node{value, nullptr,nullptr};

    if(root==nullptr){
        root = newNode;
        return 0;
    }

    int level=0;
    Node* current = root;
    while(true){
        level++;
            if(value <= current->data){
                if(current->left == nullptr){
                    current->left= newNode;
                    return level;
                }
                current = current->left;
            }
            else{
                if(current->right ==nullptr){
                    current->right = newNode;
                    return level;
                }
                current = current->right;
            }
        }
    }

int main(){
    int n;
    cin>>n;
    vector<long long > sums;
    Node* root = nullptr;

    for(int i =0 ; i<n; i++){
        int x
    }
}