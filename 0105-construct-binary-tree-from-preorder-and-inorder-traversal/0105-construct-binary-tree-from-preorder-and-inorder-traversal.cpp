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

    TreeNode*solve(vector<int>& inorder, vector<int>& preorder,int start,int end,int &idx){
        if(start>end) return NULL;

        int rootval=preorder[idx];
        int i=start;

        for(;i<=end;i++){
            if(inorder[i]==rootval) break;
        }

        idx++;

        TreeNode*root=new TreeNode(rootval);

        root->left=solve(inorder,preorder,start,i-1,idx);
        root->right=solve(inorder,preorder,i+1,end,idx);

        return root;

    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
         int n=inorder.size();
        int idx=0;
        return solve(inorder,preorder,0,n-1,idx);
    }
};