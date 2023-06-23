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

bool isSymmetric(Node* root1, Node* root2){
    if(root1 == nullptr or root2 == nullptr)
        return root1 == root2;
    if(root1->val != root2->val)
        return false;
    return isSymmetric(root1->left, root2->right) and isSymmetric(root1->right, root2->left);
}

int main(){
    // Node *root = new Node(1);
    // root->left = new Node(2);
    // root->right = new Node(3);
    // root->left->left = new Node(4);
    // root->left->right = new Node(5);
    // root->right->left = new Node(6);
    // root->right->right = new Node(7);
    // root->right->right->right = new Node(8);
    // root->right->right->right->right = new Node(9);

    // Symmetric BT
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(5);
    root->right->right = new Node(4);
    root->left->right->left = new Node(8);
    root->left->right->right = new Node(9);
    root->right->left->left = new Node(9);
    root->right->left->right = new Node(8);
    std::cout<<isSymmetric(root->left, root->right);
    return 0;
}