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

void zig_zag(Node* root, vector<vector<int>> &vec){
    if(root == NULL)
        return;
    bool check = 0;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        vector<int> temp;
        for(int i=0; i<n; i++){
            Node* node = q.front();
            q.pop();
            temp.push_back(node->val);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        if(check)
            reverse(temp.begin(), temp.end());
        check = !check;
        vec.push_back(temp);
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
    root->right->right->left = new Node(9);
    vector<vector<int>> vec;
    zig_zag(root, vec);
    for(auto it: vec){
        for(int i: it)
            std::cout<<i<<" ";
        std::cout<<endl;
    }

    return 0;
}