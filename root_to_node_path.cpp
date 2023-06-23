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

bool nodePath(Node* root, vector<int> &vec, int x){
    if(root == nullptr)
        return false;
    vec.push_back(root->val);
    if(root->val == x)
        return true;
    if(nodePath(root->left, vec, x) or nodePath(root->right, vec, x))
        return true;
    vec.pop_back();
    return false;
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
    nodePath(root, vec, 11);
    for(int it: vec)
        std::cout<<it<<" ";
    return 0;
}