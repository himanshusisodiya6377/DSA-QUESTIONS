class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
     if(root==NULL){
          TreeNode*c=new TreeNode(val);
          return c;
     } 
     else if(root->left==NULL && root->val>val){
        TreeNode*c=new TreeNode(val);
        root->left=c;
        return root;
     }
     else if(root->right==NULL && root->val<val){
         TreeNode*c=new TreeNode(val);
        root->right=c;
        return root;
     }
      else if(root->val>val) insertIntoBST(root->left,val);
        else insertIntoBST(root->right,val);
       
        return root;
    }
};