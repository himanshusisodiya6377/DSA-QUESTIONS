class Solution {
public:
    TreeNode*solve(vector<int>&preorder,vector<int>&inorder,int &idx,int lf,int end){

        if(lf>end) return NULL;

        TreeNode*root=new TreeNode(preorder[idx]);

        int id=-1;
        for(int i=lf;i<=end;i++){
            if(inorder[i]==preorder[idx]){
                id=i;
                break;
            }
        }

        // if(idx==-1) return root;
        idx++;

        root->left=solve(preorder,inorder,idx,lf,id-1);
        root->right=solve(preorder,inorder,idx,id+1,end);

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n=preorder.size();
        vector<int>in=preorder;
        sort(in.begin(),in.end());
        int i=0;
        return solve(preorder,in,i,0,n-1);
    }
};