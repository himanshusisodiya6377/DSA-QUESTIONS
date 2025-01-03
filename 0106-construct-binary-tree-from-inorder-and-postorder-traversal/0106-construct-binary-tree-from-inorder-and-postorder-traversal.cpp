class Solution {
public:
TreeNode*build(vector<int>in,int inlo,int inhi,vector<int>post,int postlo,int posthi){
    if(inhi<inlo) return NULL;
    TreeNode*node=new TreeNode(post[posthi]);
    if(inlo==inhi) return node;
    int i=inlo;
    while(i<=inhi){
        if(in[i]==post[posthi]) break;
        i++;
    }
    int leftcount=i-inlo;
    int rightcount=inhi-i;
    node->left=build(in,inlo,i-1,post,postlo,postlo+leftcount-1);
     node->right=build(in,i+1,inhi,post,postlo+leftcount,posthi-1);
    return node;
}
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        int n=in.size();
        return build(in,0,n-1,post,0,n-1);
    }
};
/*
TreeNode*build(vector<int>pre,int prelo,int prehi,vector<int>in,int inlo,int inhi){
    if(prehi<prelo) return NULL;
    TreeNode*node=new TreeNode(pre[prelo]);
    if(prelo==prehi) return node;
    int i=inlo;
    while(i<=inhi){
        if(in[i]==pre[prelo]) break;
        i++;
    }
    int leftcount=i-inlo;
    int rightcount=inhi-i;
    node->left=build(pre,prelo+1,prelo+leftcount,in,inlo,i-1);
    node->right=build(pre,prelo+leftcount+1,prehi,in,i+1,inhi);
    return node;
}
*/