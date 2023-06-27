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

int leftHeight(Node* node){
    int ht = 0;
    while(node){
        ht++;
        node = node->left;
    }
    return ht;
}

int rightHeight(Node* node){
    int ht = 0;
    while(node){
        ht++;
        node = node->right;
    }
    return ht;
}

int countNodes(Node* root){
    if(root == nullptr)
        return 0;
    int lh = leftHeight(root);
    int rh = rightHeight(root);

    if(lh == rh)
        return (1<<lh) - 1;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(11);
    cout<<countNodes(root);
    return 0;
}