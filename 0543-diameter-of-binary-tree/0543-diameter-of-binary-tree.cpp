class Solution {
public:
    int tree(TreeNode*root){
        if(root==NULL) return 0;
        return 1+max(tree(root->left),tree(root->right));
    }
     int lefttree(TreeNode*root){
        if(root==NULL) return 0;
        return 1+lefttree(root->left);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int lefttree=tree(root->left);
        int righttree=tree(root->right);
        return lefttree+righttree;
    }
};