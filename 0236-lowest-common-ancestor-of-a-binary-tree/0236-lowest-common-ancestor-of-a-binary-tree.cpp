class Solution {
public:

    bool helper(TreeNode*root,TreeNode*p,TreeNode*q){
        if(root==NULL) return false;
        if(root->val==p->val || root->val==q->val) return true;
        return helper(root->left,p,q) ||  helper(root->right,p,q);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
                // if(root->val==p->val || root->val==q->val) return root;
                // bool left=helper(root->left,p,q);
                // bool right=helper(root->right,p,q);
                // if(left && right) return root;
                // //mention return here otherwise it will return null at last
                // if(left) return lowestCommonAncestor(root->left,p,q);
                // if(right) return  lowestCommonAncestor(root->right,p,q);
                // return NULL;
                if(root==NULL) return NULL;
                if(root->val==p->val || root->val==q->val) return root;

                TreeNode*lca1=lowestCommonAncestor(root->left,p,q);
                TreeNode*lca2=lowestCommonAncestor(root->right,p,q);

                if(lca1!=NULL && lca2!=NULL) return root;
                if(lca1!=NULL) return lca1;
                return lca2;
                
    }
};