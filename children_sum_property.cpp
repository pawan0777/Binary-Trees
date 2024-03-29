#include<bits/stdc++.h>
using namespace std;
#define COUNT 10

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

struct Trunk
{
    Trunk *prev;
    string str;
 
    Trunk(Trunk *prev, string str)
    {
        this->prev = prev;
        this->str = str;
    }
};

void showTrunks(Trunk *p)
{
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
    else if (isLeft) {
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

void changeTree(Node* root){
    if(root == nullptr)
        return;
    int sum = 0;
    if(root->left)
        sum += root->left->val;
    if(root->right)
        sum += root->right->val;
    if(sum >= root->val)
        root->val = sum;
    else{
        if(root->left)
            root->left->val = root->val;
        if(root->right)
            root->right->val = root->val;
    }

    changeTree(root->left);
    changeTree(root->right);

    int total = 0;
    if(root->left) total += root->left->val;
    if(root->right) total += root->right->val;
    if(root->left or root->right) root->val = total;
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
    changeTree(root);
    cout<<"--------------------------------------------\n";
    printTree(root, nullptr, false);
    return 0;
}