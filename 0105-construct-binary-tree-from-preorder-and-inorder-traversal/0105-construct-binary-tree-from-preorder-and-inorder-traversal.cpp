class Solution {
public:
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
     int n=preorder.size();
     return build(preorder,0,n-1,inorder,0,n-1);   
    }
};