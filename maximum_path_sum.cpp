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

int height(Node *root, int &sum){
    if(root == NULL)
        return 0;
    int lh = max(0, height(root->left, sum));
    int rh = max(0, height(root->right, sum));
    sum = max(sum, lh + rh + root->val);
    return max(lh, rh) + root->val;
}

int maxPathSum(Node *root){
    int sum = INT_MIN;
    height(root, sum);
    return sum;
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
    root->right->right->right->left = new Node(9);
    std::cout<<maxPathSum(root);
    return 0;
}