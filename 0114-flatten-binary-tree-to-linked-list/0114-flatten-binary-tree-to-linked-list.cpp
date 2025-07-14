class Solution {
public:
   
   void preorder(TreeNode*root,vector<int>&pre){
    if(root==NULL) return ;
     
     pre.push_back(root->val);
     preorder(root->left,pre);
     preorder(root->right,pre);
   }
 
    void flatten(TreeNode* root) {
        if(root==NULL) return;
        vector<int>pre;
        preorder(root,pre);
         root->left=NULL;
         TreeNode*temp=root;
        for(int i=1;i<pre.size();i++){
            TreeNode*c=new TreeNode(pre[i]);
            root->right=c;
            root=root->right;
        }
        root=temp;
    }
};