#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* insert(Node* root, int value) {
    Node* newNode = new Node{value, nullptr, nullptr};

    if (root == nullptr) return newNode;

    Node* current = root;
    while (true) {
        if (value < current->data) {
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

void inorder(Node* node) {
    if (node == nullptr) return;
    inorder(node->left);
    cout << node->data << ' ';
    inorder(node->right);
}

int findMin(Node* root) {
    Node* current = root;
    while (current->left != nullptr) {
        current = current->left;
    }
    return current->data;
}

int height(Node* root){
    if(root == nullptr){
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + max(leftHeight,rightHeight);
}

bool search(Node* root, int target) {
    Node* current = root;
    while (current != nullptr) {
        if (target == current->data) return true;
        if (target < current->data) current = current->left;
        else current = current->right;
    }
    return false;
}

int main() {
    int n;
    cin >> n;

    Node* root = nullptr;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        root = insert(root, x);
    }

    inorder(root);
    cout << "\n" << search(root, 6) << "\n";
cout << findMin(root) << "\n";
cout << height(root) << "\n";
    return 0;

}

