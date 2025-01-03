class Solution {
public:
TreeNode*build(vector<int>pre,int prelo,int prehi,vector<int>post,int postlo,int posthi){
    if(prehi<prelo) return NULL;
    TreeNode*node=new TreeNode(pre[prelo]);
    if(prelo==prehi) return node;
    int i=postlo;
    while(i<=posthi){
        if(post[i]==pre[prelo+1]) break;
        i++;
    }
    int leftcount=i-postlo+1;
    node->left=build(pre,prelo+1,prelo+leftcount,post,postlo,postlo+leftcount);
    node->right=build(pre,prelo+leftcount+1,prehi,post,i+1,posthi-1);
    return node;
}
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int n=pre.size();
        return build(pre,0,n-1,post,0,n-1);
    }
};