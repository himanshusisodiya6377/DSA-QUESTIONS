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
    typedef unsigned long long ll;
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,ll>>q;
        ll ans=0;
        // long long first=-1;
        // if(root==NULL) return 0;
        q.push({root,0});
        while(!q.empty()){
            ll l=q.front().second;
            ll r=q.back().second;
            ans=max(ans,r-l+1);
            int n=q.size();
            for(int i=0;i<n;i++){
                auto p=q.front(); q.pop();
                ll idx=p.second;
                // if(i==0) first=p.second;
                // if(i==n-1) ans=max(ans,p.second-first+1);

                if(p.first->left) q.push({p.first->left,1LL*2*idx+1});
                if(p.first->right) q.push({p.first->right,1LL*2*idx+2});
            }
        }
        return ans;
    }
};