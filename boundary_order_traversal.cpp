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

bool isLeaf(Node* root){
    return (!root->left and !root->right);
}

// Traversing the left part of the tree
void left_traversal(Node* root, vector<int> &vec){
    while(root){
        if(!isLeaf(root))
            vec.push_back(root->val);
        if(root->left)
            root = root->left;
        else
            root = root->right;
    }
}

// Inorder traversal to get only the leaf node in left to right direction
void leaf_traversal(Node* root, vector<int> &vec){
    if(root == nullptr)
        return;
    leaf_traversal(root->left, vec);
    if(isLeaf(root))
        vec.push_back(root->val);
    leaf_traversal(root->right, vec);
}

void right_traversal(Node* root, vector<int> &vec){
    int n = vec.size();
    while(root){
        if(!isLeaf(root))
            vec.push_back(root->val);
        if(root->right)
            root = root->right;
        else
            root = root->left;
    }
    reverse(vec.begin() + n, vec.end());
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
    vector<int> vec;
    vec.push_back(root->val);
    left_traversal(root->left, vec);
    leaf_traversal(root, vec);
    right_traversal(root->right, vec);
    for(int it: vec)
        std::cout<<it<<" "; 
    return 0;
}