class Solution {
public:
    void solve(TreeNode*root,vector<int>&ans){
        if(root==NULL) return;
        solve(root->left,ans);
        ans.push_back(root->val);
        solve(root->right,ans);
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {

        int q=queries.size();
        vector<int>ans; //store node values here

        solve(root,ans); 
        int n=ans.size();

        vector<vector<int>>sol;

        for(auto &it : queries){

            auto t=lower_bound(ans.begin(),ans.end(),it)-ans.begin();
            cout<<t<<endl;
            
            if(t==n) sol.push_back({ans[--t],-1});
            else if(ans[t]==it) sol.push_back({ans[t],ans[t]});
            else{
               if(t!=0) sol.push_back({ans[--t],ans[++t]});
               else sol.push_back({-1,ans[t]});
            }
        }

        return sol;
    }
};