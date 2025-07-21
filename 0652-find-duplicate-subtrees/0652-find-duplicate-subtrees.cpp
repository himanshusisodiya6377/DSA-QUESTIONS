class Solution {
public:

    string duplicate(TreeNode*root,unordered_map<string,int>&mp,vector<TreeNode*>&ans){
        if(root==NULL) return "N";
        string s=to_string(root->val)+","+duplicate(root->left,mp,ans)+","+  duplicate(root->right,mp,ans);
        if(mp[s]==1){
            ans.push_back(root);
        }
        mp[s]++;
        return s;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*>ans;
        unordered_map<string,int>mp;
        duplicate(root,mp,ans);
        return ans;
    }
};