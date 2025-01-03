class Solution {
public:
void path(TreeNode*root,int target,vector<vector<int>>&ans,vector<int>v){
   if(root==NULL) return;
   if(root->val==target && root->left==NULL && root->right==NULL){
     v.push_back(root->val);
    ans.push_back(v);
    return;
   }
   v.push_back(root->val);
   path(root->left,target-(root->val),ans,v);
   path(root->right,target-(root->val),ans,v);
   return;
}
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>v;
        path(root,targetSum,ans,v);
        return ans;
    }
};