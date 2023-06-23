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

int height(Node *root){
    if(root == NULL)
        return 0;
    int lh = height(root->left);
    if(lh == -1) return -1; // Changed for the isBalanced function
    int rh = height(root->right);
    if(rh == -1) return -1; // Changed for the isBalanced function

    if(abs(lh - rh) > 1) return -1; // Changed for the isBalanced function
    return 1 + max(lh, rh);
}

bool isBalanced(Node *root){
    return height(root) != -1;
}

int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->right->right = new Node(8);
    root->right->right->right->right = new Node(9);
    std::cout<<isBalanced(root);
    return 0;
}