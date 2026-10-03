#include <iostream>
#include <queue>

using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};


Node* insert(Node* root, int value){
    Node* newNode = new Node{value , nullptr , nullptr};

    if(root == nullptr){
        return newNode;
    }

    Node* current = root;

    while(true){
        if(value<= current->data){
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
int main(){

    int n;
    cin>>n;
    Node* root = nullptr;

    for(int i = 0; i<n; i++){
        int x;
        cin>>x;
        root = insert(root,x);
    }

    int answer = 0;
    queue < Node* > q;
    q.push(root);

    while(!q.empty()){
        Node* current = q.front();
        q.pop();

        if(current->left != nullptr && current->right != nullptr){
            answer++;
        }
        if(current->left!= nullptr){
            q.push(current->left);
        }
        if(current->right != nullptr){
            q.push(current->right);
        }
    }

    cout<<answer<<"\n";
    return 0;
}