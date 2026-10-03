#include <iostream>
#include <vector>

using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};


Node* insert(Node* root, int value){

    Node* newNode = new Node{value,nullptr,nullptr};

    if(root == nullptr){
        return newNode;
    }

   
    Node* current = root;

    while(true){
        if(value<=current->data){
            if(current->left == nullptr){
                current ->left = newNode;
                break;
            }
            current = current->left;
        }
        else{
            if(current->right== nullptr){
                current->right = newNode;
                break;
            }
            current = current->right;
        }
    }
    return root;
}

void greaterSum(Node* node, int& sum ,vector<int>& result){
    if(node==nullptr) return;

    greaterSum(node->right , sum ,result);

    sum+=node->data;
    node->data = sum;
    result.push_back(sum);

    greaterSum(node->left , sum , result);

}

int main(){

    int n;
    cin>>n;
    Node* root = nullptr;

    for(int i =0 ;i<n; i++){
        int x;
        cin>>x;
        root = insert(root,x);
    }

    int sum = 0;
    vector<int> result;
    greaterSum(root , sum, result);

    for(int i=0;i<(int) result.size(); i++){
        cout<<result[i];
        if(i+1<(int)result.size()){
            cout<<" ";
        }
    }
    cout<<"\n";
    return 0 ;
}