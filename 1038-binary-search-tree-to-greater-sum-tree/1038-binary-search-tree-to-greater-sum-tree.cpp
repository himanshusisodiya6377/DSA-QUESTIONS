class Solution {
public:
  int helper(TreeNode*root,int &ans){
         if(root==NULL) return 0;
          helper(root->right,ans);
          ans+=root->val;
          root->val=ans;
          helper(root->left,ans);
          return root->val;
    }
    TreeNode* bstToGst(TreeNode* root) {
         int ans=0;
       helper(root,ans);
       return root;
    }
};