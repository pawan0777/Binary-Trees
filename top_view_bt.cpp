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

void topView(Node* root, vector<int> &vec){
    map<int, int> nodes;
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    while(!q.empty()){
        Node* node = q.front().first;
        int x = q.front().second;
        q.pop();
        if(nodes.find(x) == nodes.end())
            nodes[x] = node->val;
        if(node->left)
            q.push({node->left, x-1});
        if(node->right)
            q.push({node->right, x+1});
    }
    for(auto it: nodes)
        vec.push_back(it.second);
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
    vector<int> vec;
    topView(root, vec);
    for(int it: vec)
        std::cout<<it<<" ";
    return 0;
}