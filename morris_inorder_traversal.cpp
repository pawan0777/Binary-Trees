#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* right;
    Node* left;

    Node(int data){
        val = data;
        right = NULL;
        left = NULL;
    }
};

void morris_inorder(Node* root, vector<int> &inorder){
    Node* curr = root;
    while(curr != nullptr){
        if(curr->left == nullptr){
            inorder.push_back(curr->val);
            curr = curr->right;
        }
        else{
            Node* prev = curr->left;
            while(prev->right and prev->right!=curr){
                prev = prev->right;
            }
            if(prev->right == nullptr){
                prev->right = curr;
                curr = curr->left;
            }
            else{
                prev->right = nullptr;
                inorder.push_back(curr->val);
                curr = curr->right;
            }
        }
    }
}

int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->right->left = new Node(8);
    root->left->right->right = new Node(9);
    root->right->left->left = new Node(10);
    root->right->left->right = new Node(11);
    vector<int> vec;
    morris_inorder(root, vec);
    for(int it: vec)
        cout<<it<<" ";
    return 0;
}