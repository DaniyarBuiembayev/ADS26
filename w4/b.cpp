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

int countNodes(Node* node) {
    if (node == nullptr) {
        return 0;
    }

    int leftCount = countNodes(node->left);
    int rightCount = countNodes(node->right);

    return 1 + leftCount + rightCount;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    Node* root = nullptr;
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        root = insert(root, value);
    }

    int x;
    cin >> x;

    Node* current = root;
    while (current->data != x) {
        if (x < current->data) {
            current = current->left;
        }
        else {
            current = current->right;
        }
    }

    cout << countNodes(current) << "\n";
    return 0;
}