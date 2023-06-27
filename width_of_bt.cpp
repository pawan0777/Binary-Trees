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

int widthOfBT(Node* root){
    queue<pair<Node*, int>> q;
    int ans = 0;
    q.push({root, 0});
    while(!q.empty()){
        int minn = q.front().second;
        int size = q.size();
        int fi, la;
        for (int i = 0; i < size; i++){
            Node* node = q.front().first;
            int curr = q.front().second - minn;
            q.pop();
            if(i == 0)
                fi = curr;
            if(i == size-1)
                la = curr;
            if(node->left)
                q.push({node->left, curr*2 + 1});
            if(node->right)
                q.push({node->right, curr*2 + 2});
        }
        ans = max(ans, la - fi + 1);
    }
    return ans;
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
    std::cout<<widthOfBT(root);
    return 0;
}