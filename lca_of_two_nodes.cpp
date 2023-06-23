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

Node* lca(Node* root, Node* p, Node* q){
    if(root == nullptr or root == p or root == q)
        return root;
    Node* left = lca(root->left, p, q);
    Node* right = lca(root->right, p, q);
    if(left == nullptr)
        return right;
    else if(right == nullptr)
        return left;
    else 
        return root;
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
    Node* ans = lca(root, root->left->left, root->left->right->left);
    std::cout<<ans->val;
    return 0;
}