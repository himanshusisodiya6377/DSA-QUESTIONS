/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxi=INT_MIN;

    int solve(TreeNode*root){
         if(root==NULL) return 0;
        
        int lf=solve(root->left);
        int rg=solve(root->right);

        int ans=INT_MIN;
        ans=max(ans,root->val);
        ans=max(ans,root->val+lf);
        ans=max(ans,root->val+rg);
        ans=max(ans,root->val+rg+lf);
        
        // cout<<ans<<" ";
        maxi=max(maxi,ans);
        // cout<<maxi<<endl;

        // if(ans==INT_MIN) return 0;
        return max(root->val+lf,max(root->val+rg,root->val));
    }

    int maxPathSum(TreeNode* root) {
        solve(root);
        return maxi;    
    }
};