
class Solution {
public:
int TreeSize(TreeNode*root){
    if(root==NULL) return 0;
    return 1+max(TreeSize(root->left),TreeSize(root->right));
}
vector<int> display(TreeNode*root,vector<int>&v,int m,int n){
    if(root==NULL) return {};
    if(m==n){
       v.push_back(root->val);
       return v;
    }
    display(root->left,v,m+1,n);
    display(root->right,v,m+1,n);
    return v;
}
vector<int> displayrev(TreeNode*root,vector<int>&v,int m,int n){
    if(root==NULL) return {};
    if(m==n){
       v.push_back(root->val);
       return v;
    }
    displayrev(root->right,v,m+1,n);
     displayrev(root->left,v,m+1,n);
    return v;
}
    vector<vector<int>>zigzagLevelOrder(TreeNode* root) {
     int n = TreeSize(root);
     vector<vector<int>>v;
     for(int i=0;i<n;i++){
        vector<int>ans;
       if(i%2==0) display(root,ans,0,i);
       else displayrev(root,ans,0,i);
        v.push_back(ans);
     }    
     return v;
    }
};