/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    void solve(Node*root,priority_queue<pair<int,int>>&pq,int k,int target){
        if(root==NULL) return;
        solve(root->left,pq,k,target);
        if(pq.size()<k) pq.push({abs(target-root->data),root->data});
        else {
            if(pq.top().first>(abs(target-root->data))){
                pq.pop();
                pq.push({abs(target-root->data),root->data});
            }
        }
        solve(root->right,pq,k,target);
    }
    vector<int> getKClosest(Node* root, int target, int k) {
        // code here
        priority_queue<pair<int,int>>pq;
        // pq.push({abs(target-root->data),root->data});
        solve(root,pq,k,target);
        vector<int>ans;
        // cout<<pq.size();
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};