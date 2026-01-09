class Solution {
public:
    int first=-1,second=-1;
    vector<int>ans;
    void getInorder(TreeNode*root){
        if(root==NULL) return;

        TreeNode*curr=root;

        while(curr){
            if(!curr->left){
                ans.push_back(curr->val);
                curr=curr->right;
            }
            else{
                TreeNode*pred=curr->left;

                while(pred->right && pred->right!=curr) pred=pred->right;

                if(!pred->right){
                    pred->right=curr;
                    curr=curr->left;
                }
                else{
                    pred->right=NULL;
                    ans.push_back(curr->val);
                    curr=curr->right;
                }
            }
        }
    }
    void recover(TreeNode*root){
        if(root==NULL) return;

        TreeNode*curr=root;

        while(curr){
            if(!curr->left){
                if(curr->val==first || curr->val==second){
                    if(curr->val==first) curr->val=second;
                    else curr->val=first;
                }
                // ans.push_back(curr->val);
                curr=curr->right;
            }
            else{
                TreeNode*pred=curr->left;

                while(pred->right && pred->right!=curr) pred=pred->right;

                if(!pred->right){
                    pred->right=curr;
                    curr=curr->left;
                }
                else{
                    pred->right=NULL;
                    // ans.push_back(curr->val);
                    if(curr->val==first || curr->val==second){
                    if(curr->val==first) curr->val=second;
                    else curr->val=first;
                }
                    curr=curr->right;
                }
            }
        }
    }
    void recoverTree(TreeNode* root) {
        getInorder(root);
        for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
        vector<int>t=ans;
        sort(t.begin(),t.end());

        for(int i=0;i<ans.size();i++){
            if(t[i]!=ans[i]){
                if(first==-1) first=t[i];
                second=t[i];
            }
        }

        cout<<first<<" "<<second;

        recover(root);
        
    }
};