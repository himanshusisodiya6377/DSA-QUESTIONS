class Solution {
  public:
    void solve(Node*root,int key,vector<Node*>&ans){
        if(root==NULL) return;
        
        int diff=root->data-key; //can be -ve and can be +ve
        
        if(diff>0){
            if(ans[1]==NULL) ans[1]=root;
            else if(diff<(ans[1]->data-key)){
                ans[1]=root;
            }
        }
        else if(diff<0){
            if(ans[0]==NULL) ans[0]=root;
            else if(abs(diff)<(key-ans[0]->data)) ans[0]=root;
        }
        
        solve(root->left,key,ans);
        solve(root->right,key,ans);
        
    }
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        vector<Node*>ans(2,NULL);
        solve(root,key,ans);
        return ans;
    }
};