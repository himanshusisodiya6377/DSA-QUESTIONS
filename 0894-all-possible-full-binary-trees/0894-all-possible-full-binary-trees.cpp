class Solution {
public:
    unordered_map<int,vector<TreeNode*>>mp;

    vector<TreeNode*>solve(int n){
        if(n%2==0) return {};
        if(n==1){
            TreeNode*node=new TreeNode(0);
            return {node};
        }
        
        if(mp.find(n)!=mp.end()) return mp[n];

         vector<TreeNode*>ans;

        for(int i=1;i<n;i+=2){
           
           vector<TreeNode*>lf=solve(i);
           vector<TreeNode*>rg=solve(n-i-1);

           for(auto &l : lf){
            for(auto &r : rg){
                TreeNode*node =new TreeNode(0);
                node->left=l;
                node->right=r;
                ans.push_back(node);
            }
           }
        }
        return mp[n]=ans;
    }
    vector<TreeNode*> allPossibleFBT(int n) {
       return solve(n);        
    }
};