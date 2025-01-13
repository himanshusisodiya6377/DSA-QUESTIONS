class Solution {
public:
    void helper(vector<int>&v,TreeNode* root){
          if(root==NULL) return;
          helper(v,root->left);
          v.push_back(root->val);
           helper(v,root->right);
           return;
    }
    bool isValidBST(TreeNode* root) {
        vector<int>v;
        helper(v,root);
        for(int i=0;i<v.size()-1;i++){
            if(v[i]>=v[i+1]) return false;
        }
        return true;
    }
};