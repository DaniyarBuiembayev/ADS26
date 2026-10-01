#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

int insert(Node*& root, int value) {
    Node* newNode = new Node{value, nullptr, nullptr};
    if (root == nullptr) {
        root = newNode;
        return 0;
    }

    Node* current = root;
    int level = 0;
    while (true) {
        level++;
        if (value < current->data) {
            if (current->left == nullptr) {
                current->left = newNode;
                return level;
            }
            current = current->left;
        }
        else {
            if (current->right == nullptr) {
                current->right = newNode;
                return level;
            }
            current = current->right;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    Node* root = nullptr;
    vector<long long> sums;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        int level = insert(root, x);

        if (level == (int)sums.size()) {
            sums.push_back(0);
        }
        sums[level] += x;
    }

    cout << sums.size() << "\n";
    for (int i = 0; i < (int)sums.size(); i++) {
        cout << sums[i] << " ";
    }
    cout << "\n";
    return 0;
}