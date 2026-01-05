class Solution {
public:
    int solve(TreeNode*root,int mask){
        if(root==NULL) return 0;
        
        
        if(root->left==NULL && root->right==NULL){
            mask^=(1<<root->val);
            if ((mask & (mask - 1)) == 0) return 1;
            return 0;
        }
        
        mask^=(1<<root->val);

        return solve(root->left,mask) + solve(root->right,mask);
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        //marking fir use of bit set in it
        return solve(root,0);
    }
};