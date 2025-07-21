class Solution {
public:

   void dfs(TreeNode*root, unordered_map<int,int>&mp,int &ans){
       
       if(root==NULL) return; 
       
       if(root->left==NULL && root->right==NULL){
        mp[root->val]++;
        int cnt=0;
        for(auto v : mp){
            if(v.second%2!=0) cnt++;
        }
         if(cnt<=1) ans++;

          mp[root->val]--;
         if(mp[root->val]==0){
          mp.erase(root->val);
         }

         return;
       }
       
       mp[root->val]++;
       dfs(root->left,mp,ans);
       dfs(root->right,mp,ans);
       mp[root->val]--;
       if(mp[root->val]==0){
        mp.erase(root->val);
       }
   }

    int pseudoPalindromicPaths (TreeNode* root) {
        unordered_map<int,int>mp;
        int ans=0;
        dfs(root,mp,ans);
        return ans;
    }
};