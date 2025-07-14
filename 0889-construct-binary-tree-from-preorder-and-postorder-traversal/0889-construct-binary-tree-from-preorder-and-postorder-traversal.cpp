class Solution {
public:
    TreeNode* build(vector<int>& pre,int prestart,int preend,
               vector<int>& post,int poststart,int postend){

        if(prestart>preend) return NULL;

        int k=pre[prestart];
        TreeNode* root=new TreeNode(k);  

        if(prestart==preend) return root;

        int left_root=pre[prestart+1];

        int i=poststart;
        while(i<=postend){
            if(post[i]==left_root) break;
            i++;
        }  

        int l=i-poststart+1;

        root->left=build(pre, prestart+1, prestart+l, post, poststart, i);
        root->right=build(pre, prestart+l+1, preend, post, i+1, postend-1);
        return root;
    }


    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post){
        int n=pre.size();
        return build(pre,0,n-1,post,0,n-1);
        return NULL;
    }
};