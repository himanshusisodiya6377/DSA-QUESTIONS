class Solution {
public:
    int height(TreeNode*root){
        if(root==NULL) return 0;
        return 1+max(height(root->left),height(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        int x=height(root->left);
        int y=height(root->right);
        if(abs(x-y)>1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
};