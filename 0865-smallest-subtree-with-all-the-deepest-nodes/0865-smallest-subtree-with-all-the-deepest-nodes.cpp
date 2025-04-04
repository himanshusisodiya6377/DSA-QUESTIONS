class Solution {
public:
       int levels(TreeNode*root){
        if(root==NULL) return 0 ;
        return 1+max(levels(root->left),levels(root->right));
    }
    TreeNode*getLCA(TreeNode*root,int level,int start){
        if(root==NULL) return NULL;
        if(start==level-1){
            if(root==NULL) return NULL;
            else if(root->left!=NULL && root->right!=NULL) return root;
            else if(root->left==NULL && root->right!=NULL) return root->right;
            else if(root->left!=NULL && root->right==NULL) return root->left;
            else return NULL;
        }
        TreeNode*let=getLCA(root->left,level,start+1);
        TreeNode*rig=getLCA(root->right,level,start+1);
        if(let==NULL && rig!=NULL) return rig;
        else if(let!=NULL && rig==NULL) return let;
        else if(let!=NULL && rig!=NULL) return root;
        else return NULL;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int level=levels(root);
        if(level==1) return root;
       TreeNode*ans=getLCA(root,level,1);
       return ans;
    }
};