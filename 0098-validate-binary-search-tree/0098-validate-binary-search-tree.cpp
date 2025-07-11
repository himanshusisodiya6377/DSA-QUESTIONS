class Solution {
public:

    bool helper(TreeNode*root,long maxi,long mini){
        if(root==NULL) return true;
        if(root->val<=maxi || root->val>=mini) return false;
        return helper(root->left,maxi,root->val) && helper(root->right,root->val,mini);
    }
 
    bool isValidBST(TreeNode* root) {
        return helper(root,LONG_MIN,LONG_MAX);
    }
};