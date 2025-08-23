class Solution {
public:
      
    void solve(TreeNode*root,unordered_map<long long,long long>&mp,long long level){
        if(root==NULL) return;
         
        if(mp.find(level)==mp.end()) mp[level]=root->val;
        else mp[level]+=root->val;

        if(root->left!=NULL) solve(root->left,mp,level+1);
        if(root->right!=NULL) solve(root->right,mp,level+1);
        
    }

    long long kthLargestLevelSum(TreeNode* root, int k) {
        unordered_map<long long,long long>mp;
        solve(root,mp,1);
        priority_queue<long long>pq;

        for(auto it : mp){
            pq.push(it.second);
        }

        if(pq.size()<k) return -1;
        else{
            while(pq.size()>0 && k>1){
                pq.pop();
                k--;
            }
        }

        return pq.top();
    }
};