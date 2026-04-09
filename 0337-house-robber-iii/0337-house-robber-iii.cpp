class Solution {
public:
    map<pair<TreeNode*,bool>,int>mp;
    int solve(TreeNode*root,bool flag){
         if(root==NULL) return 0;
          
          if(mp.find(make_pair(root,flag))!=mp.end()) return mp[make_pair(root,flag)];
         int inc=0;
         if(!flag){
            inc=root->val+solve(root->left,true)+solve(root->right,true);
         }
         
         int not_inc=solve(root->left,false)+solve(root->right,false);

         return mp[make_pair(root,flag)]=max(inc,not_inc);
    }
    int rob(TreeNode* root) {
         //false --> we can include
         //true -->skip
         return solve(root,false);        
    }
};