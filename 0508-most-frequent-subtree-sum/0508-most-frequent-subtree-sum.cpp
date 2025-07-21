class Solution {
public:

   int dfs(TreeNode*root,unordered_map<int,int>&mp,vector<int>&ans){
    
    if(root==NULL) return 0;
     
    if(root->left==NULL && root->right==NULL){
    mp[root->val]++;
    return root->val;
    }
        

    root->val+=(dfs(root->left,mp,ans)+dfs(root->right,mp,ans));
        
    mp[root->val]++;

    return root->val;

   }

    vector<int> findFrequentTreeSum(TreeNode* root) {
     vector<int>ans;
     unordered_map<int,int>mp; 
     dfs(root,mp,ans);

       int freq=-1;

       for(auto v : mp){
         freq=max(freq,v.second);
       } 
       for(auto v : mp){
        if(freq==v.second) ans.push_back(v.first);
       }       
       return ans;
    }
};