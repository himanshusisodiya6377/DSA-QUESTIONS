class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
     if(root->left==NULL || root->right==NULL){
        TreeNode*c=new TreeNode(val);
        if(root->val>val) root->left=c;
        else root->right=c;
        return root;
     }
        if(root->val>val) insertIntoBST(root->left,val);
        else insertIntoBST(root->right,val);
        return root;
    }
};