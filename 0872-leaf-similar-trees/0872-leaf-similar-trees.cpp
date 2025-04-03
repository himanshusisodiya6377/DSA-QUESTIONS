
class Solution {
public:
    void check(TreeNode*root,vector<int>&v){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            v.push_back(root->val);
            return;
        }
        check(root->left,v);
        check(root->right,v);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>tree1;
        vector<int>tree2;
        check(root1,tree1);
        check(root2,tree2);
        return tree1==tree2;
    }
};