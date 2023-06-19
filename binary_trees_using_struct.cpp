#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* right;
    Node* left;

    Node(int data){
        val = data;
        right = NULL;
        left = NULL;
    }
};

void inorder(Node* root){
    if(root == NULL)
        return;
    inorder(root->left);
    std::cout<<root->val<<" ";
    inorder(root->right);
}

void preorder(Node* root){
    if(root == NULL)
        return;
    std::cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root){
    if(root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    std::cout<<root->val<<" ";
}

int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    inorder(root);
    std::cout<<endl;
    preorder(root);
    std::cout<<endl;
    postorder(root);
    std::cout<<endl;
    return 0;
}