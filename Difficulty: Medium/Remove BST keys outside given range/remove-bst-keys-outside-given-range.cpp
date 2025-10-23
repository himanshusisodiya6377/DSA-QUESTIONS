/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    Node* preorder(Node*root){
        Node*temp=root->left;
        while(temp->right){
            temp=temp->right;
        }
        return temp;
    }
    Node*deleteNode(Node*root,int val){
        if(root==NULL) return NULL;
        if(root->data==val){
        if(root->left==NULL && root->right==NULL) return NULL;
        
        if (root->left == NULL) return root->right;
        if (root->right == NULL) return root->left;
    
            Node*pre=preorder(root);
            root->data=pre->data;
            root->left=deleteNode(root->left,pre->data);
        }
        else if(root->data<val) root->right=deleteNode(root->right,val);
        else root->left=deleteNode(root->left,val);
        return root;
        
    }
    Node* removekeys(Node* root, int l, int r) {
        // code here
        if(root==NULL) return NULL;
        root->left=removekeys(root->left,l,r);
        root->right=removekeys(root->right,l,r);
        
        if(root->data<l){
            Node*righttree=root->right;
            deleteNode(root,root->data);
            return righttree;
        }
         if(root->data>r){
            Node*lefttree=root->left;
            deleteNode(root,root->data);
            return lefttree;
        }
        return root;
    }
};