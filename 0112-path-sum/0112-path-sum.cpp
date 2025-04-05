class Solution {
public:
    // our approach include a sum which increases so that when sum eqaul to
    // target result in true but its not feasible to handle if we use only
    // target and subtract it every time with noda and pass it by value and when
    // it reach the leaf node we can check whether we reach our target or not in
    // this ways its easy to handle
    //  void path(TreeNode*root,int target,int &x){
    //     if(root==NULL) return;
    //     if(root->val==target && root->left==NULL && root->right==NULL){
    //      x=1;
    //      return;
    //     }
    //     path(root->left,target-(root->val),x);
    //     path(root->right,target-(root->val),x);
    //     return;
    //  }
    bool path(TreeNode* root, int target, int sum) {
        if (root == NULL)
            return false;
        // sum += root->val;
        // if (sum == target && root->left == NULL && root->right == NULL)
        //     return true;
        // bool let = path(root->left, target, sum);
        // bool rig = path(root->right, target, sum);
        // if (let || rig)
        //     return true;
        // else
        //     return false;

    sum += root->val;

    if (root->left == nullptr && root->right == nullptr) {
        return sum == target;
    }

    return path(root->left, target, sum) || path(root->right, target, sum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int x = 0;
        return path(root, targetSum, x);
        // if(x==1) return true;
        // else return false;
    }
};