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

void leftView(Node* root, int level, vector<int> &vec){
    if(root == nullptr)
        return;
    if(level == vec.size())
        vec.push_back(root->val);
    leftView(root->left, level+1, vec);
    leftView(root->right, level+1, vec);
}

void rightView(Node* root, int level, vector<int> &vec){
    if(root == nullptr)
        return;
    if(level == vec.size())
        vec.push_back(root->val);
    rightView(root->right, level+1, vec);
    rightView(root->left, level+1, vec);
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
    root->right->left->right->left = new Node(12);
    vector<int> vec1, vec2;
    rightView(root, 0, vec1);
    leftView(root, 0, vec2);
    for(int it: vec1)
        std::cout<<it<<" ";
    return 0;
}