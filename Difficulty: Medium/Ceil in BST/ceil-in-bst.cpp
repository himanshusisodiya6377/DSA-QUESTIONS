class Solution {
  public:
    void solve(Node*root,int x,int &ans){
        if(root==NULL) return ;
        
        if(root->data>=x) ans=min(ans,root->data);
        
        solve(root->left,x,ans);
        solve(root->right,x,ans);
    }
    int findCeil(Node* root, int x) {
        // code here
        int ans=INT_MAX;
        solve(root,x,ans);
        return (ans==INT_MAX ? -1 : ans);
    }
};
