/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int solve(TreeNode* root, vector<int>& lf, vector<int>& rg) {
        if (root == NULL)
            return 0;

        int left = solve(root->left, lf, rg);
        int right = solve(root->right, lf, rg);

        lf[root->val] = left;
        rg[root->val] = right;

        return left + right + 1;
    }
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        vector<int> lf(n + 1, 0);
        vector<int> rg(n + 1, 0);

        solve(root, lf, rg);

        int left_node=lf[x];
        int right_node=rg[x];
        int parent_node=n-(left_node+right_node+1);

        for(int i=0;i<n+1;i++){
            cout<<lf[i]<<" "<<rg[i]<<" "<<i<<endl;
        }

        vector<int>ans;
        ans.push_back(left_node);
        ans.push_back(right_node);
        ans.push_back(parent_node);

        sort(ans.begin(),ans.end());
        int gain_first=ans[1]+ans[0]+1;
        int second_gain=ans[2];

        return second_gain>gain_first;
    }
};