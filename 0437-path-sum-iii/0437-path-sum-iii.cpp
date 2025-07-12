class Solution {
public:

    void helper(TreeNode*root,long long sum,long long targetSum,long long &path){
       
        if(root==NULL) return;
       

        if(sum+root->val==targetSum) {
            path++;
        
        }
       
      helper(root->left,sum+root->val,targetSum,path);
      helper(root->right,sum+root->val,targetSum,path);
    }
   
   void pathcount(TreeNode*root,long long targetSum,long long &path){
         if(root==NULL) return;
         long long sum=0;
         helper(root,sum,targetSum,path);
        
         pathcount(root->left,targetSum,path);
         pathcount(root->right,targetSum,path);
   }
 
    int pathSum(TreeNode* root, long long targetSum) {
        long long path=0;
        pathcount(root,targetSum,path);
        return path;
    }
};