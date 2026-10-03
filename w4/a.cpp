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
    if (root == nullptr){
        return newNode;
    }

    Node* current = root;
    while (true) {
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

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    Node* root = nullptr;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        root = insert(root, x);
    }

    for (int i = 0; i < q; i++) {
        string s;
        cin >> s;

        Node* current = root;
        for (char c : s) {
            if (c == 'L') {
                current = current->left;
            }
            else {
                current = current->right;
            }
        
            if (current == nullptr) {
                break;
            }
        }

        if (current != nullptr){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
            }
    }
    return 0;
}