class Solution {
public:
    long long ans=0;
    long long mod=1e9+7;
     long long Total_sum(TreeNode*root){
        if(root==NULL) return 0;

         long long lf=Total_sum(root->left);
         long long rg=Total_sum(root->right);

        return root->val+lf+rg;
    }

     long long solve(TreeNode*root,int sum){
        if(root==NULL) return 0;

         long long lf=solve(root->left,sum);
         long long rg=solve(root->right,sum);
        
         long long sol=lf+rg+root->val;

        ans=max(ans,(sum-sol)*(sol));
        // ans=ans%mod;

        return sol;
    }
    int maxProduct(TreeNode* root) {
         long long sum=Total_sum(root);
        solve(root,sum);
        return ans%mod;
    }
};