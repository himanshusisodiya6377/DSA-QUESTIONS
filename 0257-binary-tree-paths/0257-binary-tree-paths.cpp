class Solution {
public:
    void path(TreeNode*root,vector<string>&ans,string v){
   if(root==NULL) return;
   if(root->left==NULL && root->right==NULL){
    v+=to_string(root->val);
    ans.push_back(v);
    return;
   }
    v+=to_string(root->val);
   path(root->left,ans,v+"->");
   path(root->right,ans,v+"->");
   return;
}
    vector<string> binaryTreePaths(TreeNode* root) {
      vector<string>ans;
      string s;
      path(root,ans,s);
      return ans;
    }
};