// 3 Approaches
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

// Using Recursion
// Node *prev = NULL;
// void flatten(Node* root){
//     if(root == nullptr)
//         return;
//     flatten(root->right);
//     flatten(root->left);
//     root->right = prev;
//     root->left = nullptr; 
//     prev = root;
// }

// Using Stack
// void flatten(Node* root){
//     stack<Node*> st;
//     st.push(root);
//     while(!st.empty()){
//         Node* curr = st.top();
//         st.pop();
//         if(curr->right)
//             st.push(curr->right);
//         if(curr->left)
//             st.push(curr->left);
//         if(!st.empty())
//             curr->right = st.top();
//         curr->left = nullptr;
//     }
// }

// Using Morris Traversal logic
void flatten(Node *root){
    Node* curr = root;
    while(curr){
        if(curr->left){
            Node* prev =  curr->left;
            while(prev->right){
                prev=prev->right;
            }
            prev->right=curr->right;
            curr->right = curr->left;
            curr->left=NULL;
        }
        curr=curr->right;
    }
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
    flatten(root);
    while(root){
        std::cout<<root->val<<" ";
        root = root->right;
    }
    return 0;
}