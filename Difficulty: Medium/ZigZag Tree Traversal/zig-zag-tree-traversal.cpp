/*
class Node {
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
    vector<int> zigZagTraversal(Node* root) {
        // code here
        if(root==NULL) return {};
        vector<int>ans;
        queue<Node*>q;
        q.push(root);
        ans.push_back(root->data);
        int num=2;
        while(!q.empty()){
            int n=q.size();
            vector<int>ch;
            for(int i=0;i<n;i++){
            Node*temp=q.front();
            q.pop();
            if(temp->left!=NULL) {
                ch.push_back(temp->left->data);
                q.push(temp->left);
            }
             if(temp->right!=NULL) {
                ch.push_back(temp->right->data);
                q.push(temp->right);
            }
            }
            if(num%2==0) reverse(ch.begin(),ch.end());
            for(int j=0;j<ch.size();j++) ans.push_back(ch[j]);
            num++;
            // ans.push_back(ch);
        }
        return ans;
    }
};