class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
     TreeNode*curr=root;
     vector<int>ans;

     while(curr!=NULL){

        if(curr->left==NULL){
            ans.push_back(curr->val);
            curr=curr->right;
        }
        else{
            TreeNode*leftnode=curr->left;
            while(leftnode->right!=NULL) leftnode=leftnode->right;
            leftnode->right=curr;
            TreeNode*temp=curr;
            curr=curr->left;
            temp->left=NULL;
        }

     }        
     return ans;
    }
};