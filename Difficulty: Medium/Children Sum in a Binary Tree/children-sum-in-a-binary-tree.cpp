/*

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

*/

class Solution {
  public:
    bool isSumProperty(Node *root) {
   
        if(root==NULL) return true;
        
        if(root->left==NULL && root->right==NULL) return true;
        
        bool lt=isSumProperty(root->left);
        bool rt=isSumProperty(root->right);
        
        if(!lt || !rt) return false;
        
        int lf=0,rg=0;
        
        if(root->left) lf=root->left->data;
        if(root->right) rg=root->right->data;
        
        return root->data==(lf+rg) && lt && rt; 
    }
};