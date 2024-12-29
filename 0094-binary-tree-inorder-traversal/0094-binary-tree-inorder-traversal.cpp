
class Solution {
public:
     vector<int>v;
    vector<int> inorderTraversal(TreeNode* root) {
        if(root==NULL) return {};
        
        
        inorderTraversal(root->left);
        v.push_back(root->val);
       inorderTraversal(root->right);
        return v;
    }
};