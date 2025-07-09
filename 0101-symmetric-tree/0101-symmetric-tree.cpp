class Solution {
public:
  //this question is particulary easy and i hav marked it because you should do it with iterative solution 
    bool equal(TreeNode* root, TreeNode* temp) {
        if (root == NULL && temp == NULL) return true;  // Both are NULL
        if (root == NULL || temp == NULL) return false; // One is NULL
        

        // Compare values and check symmetry recursively
        // if (root->val != temp->val) return false;
        return root->val==temp->val && equal(root->left, temp->right) && equal(root->right, temp->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true; // An empty tree is symmetric
        return equal(root->left, root->right); // Check symmetry of left and right subtrees
        //BFS FOR ITERATIVE SOLUTION
        // queue<TreeNode*>q;
        // q.push(root->left);
        // q.push(root->right);
        // while(!q.empty()){
        //     TreeNode*first=q.front();
        //     q.pop();
        //     TreeNode*sec=q.front();
        //     q.pop();
        //     if(first==NULL && sec==NULL) continue;
        //     if((first==NULL || sec==NULL) || first->val!=sec->val) return false;
        //     q.push(first->left);
        //     q.push(sec->right);
        //     q.push(first->right);
        //     q.push(sec->left); 
        // }
        // return true;
    }
};
