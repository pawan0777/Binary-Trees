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

Node* createTree(vector<int> in, int iS, int iE, vector<int> post, int pS, int pE, map<int, int> inMap){
    if(pS > pE or iS > iE)
        return nullptr;

    Node* root = new Node(post[pE]);
    int inRoot = inMap[post[pE]];
    int numsLeft = inRoot - iS;
    root->left = createTree(in, iS, inRoot-1, post, pS, pS + numsLeft-1, inMap);
    root->right = createTree(in, inRoot+1, iE, post, pS + numsLeft, pE-1, inMap);
    return root;
}

int main(){
    vector<int> in{40, 20, 50, 10, 60, 30}, post{40, 50, 20, 60, 30, 10};
    map<int, int> inMap;
    for (int i = 0; i < in.size(); i++)
        inMap[in[i]] = i;
    Node* root = createTree(in, 0, in.size()-1, post, 0, post.size()-1, inMap);
    printTree(root, nullptr, false);
    return 0;
}