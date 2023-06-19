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

void preorder(Node* root){
    if(root == NULL) return;
    std::cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root){
    if(root == NULL) return;
    inorder(root->left);
    std::cout<<root->val<<" ";
    inorder(root->right);
}

void postorder(Node* root){
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    std::cout<<root->val<<" ";
}

void level_order(Node *root, vector<vector<int>> &ans){
    if(root == NULL)
        return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        vector<int> vec;
        for (int i = 0; i < n; i++){
            Node* temp = q.front();
            q.pop();
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
            vec.push_back(temp->val);
        }
        ans.push_back(vec);
    }
}

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

void left_view(Node* root, vector<int> vec){

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
    // preorder(root);
    // std::cout<<endl;
    // inorder(root);
    // std::cout<<endl;
    // postorder(root);
    // vector<vector<int>> vec;
    // level_order(root, vec);
    // for(auto it: vec){
    //     for(int i: it)
    //         std::cout<<i<<" ";
    //     std::cout<<endl;
    // }
    // std::cout<<height(root);
    std::cout<<isBalanced(root);
    return 0;
}