class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
     if(p==NULL && q==NULL) return true;
     if(p==NULL || q==NULL) return false;
     if((p->val>0 && q==NULL) || (p==NULL && q->val>0)) return false;
     if(p->val!=q->val) return false;
    return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
};

  