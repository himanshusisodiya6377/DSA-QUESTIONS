class Solution {
public:

    void helper(TreeNode*root,vector<vector<int>>&ans,vector<int>v,int targetSum,int sum){
        if(root->left==NULL && root->right==NULL){
            if(sum+root->val==targetSum){
                v.push_back(root->val);
                ans.push_back(v);
            }
        }

        v.push_back(root->val);

        if(root->left) helper(root->left,ans,v,targetSum,sum+root->val);
        if(root->right) helper(root->right,ans,v,targetSum,sum+root->val);
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return {};
        vector<vector<int>>ans;
        vector<int>v;
        int sum=0;
        helper(root,ans,v,targetSum,sum);
        return ans;
    }
};