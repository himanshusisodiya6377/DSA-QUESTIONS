class Solution {
  public:
  
   int getLevel(Node*root){
       if(root==NULL) return 0;
       return 1+max(getLevel(root->left),getLevel(root->right));
   }
   
   
   void getList(Node*root,vector<int>&ans,int level){
       if(root==NULL) return;
       if(ans[level]==-1) ans[level]=root->data;
       getList(root->left,ans,level+1);
       getList(root->right,ans,level+1);
   }
   
  
    vector<int> leftView(Node *root) {
        if(root==NULL) return {};
       int level=getLevel(root);
       vector<int>ans(level,-1);
       getList(root,ans,0);
       return ans;
    }
};