/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int height(TreeNode*root){
        if(root==NULL) return 0;
        return 1+max(height(root->left),height(root->right));
    }
    int findBottomLeftValue(TreeNode* root) {
        //  if(root==NULL) return 0;
        if(root->left==NULL && root->right==NULL) return root->val;
        int lf=height(root->left);
        int rg=height(root->right);

        if(lf>=rg) return findBottomLeftValue(root->left);
        return findBottomLeftValue(root->right);
    }
};