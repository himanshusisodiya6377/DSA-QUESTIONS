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
    unordered_set<int>st;
    vector<TreeNode*>ans;
    TreeNode* solve(TreeNode*root){
        if(root==NULL) return NULL;

        if(st.count(root->val)){
            if(root->left) helper(root->left);
            if(root->right) helper(root->right); 
            return NULL;
        }
        else{
            root->left=solve(root->left);
            root->right=solve(root->right);
        }

        return root;
    }
    void helper(TreeNode*root){
        TreeNode*t=solve(root);
        if(t) ans.push_back(t);
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for(auto &it : to_delete){
            st.insert(it);
        }

        helper(root);

        return ans;
    }
};