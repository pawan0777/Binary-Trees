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

struct Trunk{
    Trunk *prev;
    string str;
 
    Trunk(Trunk *prev, string str){
        this->prev = prev;
        this->str = str;
    }
};

void showTrunks(Trunk *p){
    if (p == nullptr)
        return;
    showTrunks(p->prev);
    cout << p->str;
}
 
void printTree(Node* root, Trunk *prev, bool isLeft){
    if (root == nullptr)
        return;
 
    string prev_str = "    ";
    Trunk *trunk = new Trunk(prev, prev_str);
    printTree(root->right, trunk, true);

    if (!prev) 
        trunk->str = "---";
    else if (isLeft){
        trunk->str = ".---";
        prev_str = "   |";
    }
    else {
        trunk->str = "`---";
        prev->str = prev_str;
    }
    
    showTrunks(trunk);
    cout << " " << root->val << endl;
    if (prev)
        prev->str = prev_str;
    trunk->str = "   |";
    printTree(root->left, trunk, false);
}

string serialize(Node* root){
    if(root == nullptr)
        return "";
    queue<Node*> q;
    q.push(root);
    string st = "";
    while(!q.empty()){
        Node* curr = q.front();
        q.pop();
        if(curr == nullptr)
            st += "#,";
        else
            st += (to_string(curr->val) + ',');
        if(curr != nullptr){
            q.push(curr->left);
            q.push(curr->right);
        }
    }
    return st;
}

Node* deserialize(string st){
    if(st.size() == 0)
        return nullptr;
    stringstream s(st);
    string str;
    getline(s, str, ',');
    Node* root = new Node(stoi(str));
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* curr = q.front();
        q.pop();

        getline(s, str, ',');
        if(str == "#")
            curr->left = nullptr;
        else{
            Node* leftNode = new Node(stoi(str));
            curr->left = leftNode;
            q.push(leftNode);
        }

        getline(s, str, ',');
        if(str == "#")
            curr->right = nullptr;
        else{
            Node* rightNode = new Node(stoi(str));
            curr->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
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
    printTree(root, nullptr, false);
    string st = serialize(root);
    std::cout<<st<<endl;
    Node* newRoot = deserialize(st);
    printTree(newRoot, nullptr, false);
    return 0;
}