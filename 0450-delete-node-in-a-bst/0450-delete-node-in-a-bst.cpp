class Solution {
public:
 
    TreeNode*predecessor(TreeNode*root){
        root=root->left;
        while(root->right!=NULL){
            root=root->right;
        }
        return root;
    }
 
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        if(root->val==key){
         //having only one child

         if(root->left==NULL && root->right==NULL){
            return NULL;
         }

         if(root->left==NULL || root->right==NULL){
            if(root->left!=NULL) return root->left;
            else return root->right;
         }

         if(root->left!=NULL && root->right!=NULL){
            TreeNode*pred=predecessor(root);
            root->val=pred->val;
            root->left = deleteNode(root->left, pred->val); 
         }
         

        }
        else if(root->val>key) root->left=deleteNode(root->left,key);
        else root->right=deleteNode(root->right,key);
        return root;
    }
};