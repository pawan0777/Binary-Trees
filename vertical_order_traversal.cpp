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

void verticalOrderTraversal(Node* root, vector<vector<int>> &vec){
    map<int, map<int, multiset<int>>> nodes;
    queue<pair<Node*, pair<int, int>>> q;
    q.push({root, {0, 0}});
    while(!q.empty()){
        auto p = q.front();
        q.pop();
        Node* node = p.first;
        int x = p.second.first, y = p.second.second;
        nodes[x][y].insert(node->val);
        if(node->left)
            q.push({node->left, {x-1, y+1}});
        if(node->right)
            q.push({node->right, {x+1, y+1}});
    }
    for(auto it: nodes){
        vector<int> temp;
        for(auto i: it.second)
            temp.insert(temp.end(), i.second.begin(), i.second.end());
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
    verticalOrderTraversal(root, vec);
    for(auto it: vec){
        for(int i: it)
            std::cout<<i<<" ";
        std::cout<<endl;
    }  
    return 0;
}