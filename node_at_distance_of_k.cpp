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

void markParents(unordered_map<Node*, Node*> &parents, Node* root){
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* curr = q.front();
        q.pop();
        if(curr->left){
            parents[curr->left] = curr;
            q.push(curr->left);
        }
        if(curr->right){
            parents[curr->right] = curr;
            q.push(curr->right);
        }
    }
}

void distanceK(Node* root, Node* target, int k, vector<int> &vec){
    unordered_map<Node*, Node*> parents;
    markParents(parents, root);
    unordered_map<Node*, bool> visited;
    queue<Node*> q;
    q.push(target);
    visited[target] = true;
    int curr_lvl = 0;
    while(!q.empty()){
        int size = q.size();
        if(curr_lvl++ == k)
            break;
        for (int i = 0; i < size; i++){
            Node* curr = q.front();
            q.pop();
            if(curr->left and !visited[curr->left]){
                q.push(curr->left);
                visited[curr->left] = true;
            }
            if(curr->right and !visited[curr->right]){
                q.push(curr->right);
                visited[curr->right] = true;
            }
            if(parents[curr] and !visited[parents[curr]]){
                q.push(parents[curr]);
                visited[parents[curr]] = true;
            }
        }
    }
    while(!q.empty()){
        vec.push_back(q.front()->val);
        q.pop();
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
    vector<int> vec;
    distanceK(root, root, 2, vec);
    for(int it: vec)
        std::cout<<it<<" ";
    return 0;
}