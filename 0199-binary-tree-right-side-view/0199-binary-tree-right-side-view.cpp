class Solution {
public:
   int level(TreeNode*a){
    if(a==NULL) return 0;
 return 1+max(level(a->left),level(a->right));
  }
  void preorder(TreeNode*root,vector<int>&ans,int n){
    if(root==NULL) return;
    ans[n]=root->val;
    preorder(root->left,ans,n+1);
    preorder(root->right,ans,n+1);
  }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans(level(root),0);
        preorder(root,ans,0);
        return ans;
    }
};