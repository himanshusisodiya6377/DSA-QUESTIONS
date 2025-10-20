/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    int gain(Node*root){
        if(root==NULL) return 0;
        int val = root->data + max(0, max(gain(root->left), gain(root->right)));
        return val;
    }
    int findMaxSum(Node *root) {
        // code here
        if(root==NULL) return INT_MIN;
        int path=root->data;
        int gl=gain(root->left);
        int gr=gain(root->right);
        if (gl > 0) path += gl;
        if (gr > 0) path += gr;
        int lt=findMaxSum(root->left);
        int rt=findMaxSum(root->right);
        // cout<<path<<" "<<lt<<" "<<rt<<endl;
        return max(path,max(lt,rt));
    }
};