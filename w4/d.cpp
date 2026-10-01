#include <iostream>
#include <string>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* insert(Node* root, int value) {
    Node* newNode = new Node{value, nullptr, nullptr};

    if (root == nullptr) {
        return newNode;
    }
    int level = 0;

    Node* current = root;
    while (true) {
        level++:
        if (value <= current->data) {
            if (current->left == nullptr) {
                current->left = newNode;
                
                break;
            }
            current = current->left;
        }
        else {
            if (current->right == nullptr) {
                current->right = newNode;
                
                break;
            }
            current = current->right;
        }
    }
    return root;
}

int main(){

    int n;
    cin>>n;
    Node* root = nullptr;
    vector<long long> sums; 

    for(int i = 0 ; i<n; i++){
        int x;
        cin>>x;
        int level = insert(root, value);

        if (level == (int)sums.size()) {
            sums.push_back(0);
        }
        sums[level] += value;

    }

    cout << sums.size() << "\n";
    for (int i = 0; i < (int)sums.size(); i++) {
        cout << sums[i] << " ";
    }
    cout << "\n";
    return 0;
}