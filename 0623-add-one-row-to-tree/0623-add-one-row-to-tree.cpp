class Solution {
public:
    void addnode(TreeNode*root,int val,int depth,int n){
        if(root==NULL) return;
        if(n+1==depth){
            TreeNode*leftnext=new TreeNode(val);
                leftnext->left=root->left;
                root->left=leftnext;

                TreeNode*rightnext=new TreeNode(val);
                 rightnext->right=root->right;
                root->right=rightnext;
        }
       else{ 
         addnode(root->left,val,depth,n+1);
        addnode(root->right,val,depth,n+1);
       }
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode*next=new TreeNode(val);
            next->left=root;
            return next;
        }
        addnode(root,val,depth,1);
        return root;
    }
};