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
    vector<vector<int>> vec;
    level_order(root, vec);
    for(auto it: vec){
        for(int i: it)
            std::cout<<i<<" ";
        std::cout<<endl;
    }
    return 0;
}