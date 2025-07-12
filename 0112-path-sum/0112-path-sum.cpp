class Solution {
public:
 
    bool helper(TreeNode*root,int sum,int targetSum){
       
    //    if(root==NULL) return false;
       
       if(root->left==NULL && root->right==NULL){
        if(sum+root->val==targetSum) return true;
        else return false;
       }
        
       bool leftcall,rightcall;
      if(root->left!=NULL)  leftcall=helper(root->left,sum+root->val,targetSum);
      if(root->right!=NULL) rightcall=helper(root->right,sum+root->val,targetSum);
       return leftcall || rightcall;
    }
 
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return false;
        int sum=0;
        return helper(root,sum,targetSum);
    }
};