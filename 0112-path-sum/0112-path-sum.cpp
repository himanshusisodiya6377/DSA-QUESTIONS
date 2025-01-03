class Solution {
public:
void path(TreeNode*root,int target,int &x){
   if(root==NULL) return;
   if(root->val==target && root->left==NULL && root->right==NULL){
    x=1;
    return;
   }
   path(root->left,target-(root->val),x);
   path(root->right,target-(root->val),x);
   return;
}
    bool hasPathSum(TreeNode* root, int targetSum) {
        int x=0;
        path(root,targetSum,x);
        if(x==1) return true;
        else return false;
    }
};