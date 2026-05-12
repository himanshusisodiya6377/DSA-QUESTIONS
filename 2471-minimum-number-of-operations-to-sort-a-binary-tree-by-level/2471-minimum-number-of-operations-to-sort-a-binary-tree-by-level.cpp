class Solution {
public:
   int minSwaps(vector<int>& arr) {
    int n = arr.size();

    vector<pair<int,int>> v;

    for(int i = 0; i < n; i++) {
        v.push_back({arr[i], i});
    }

    sort(v.begin(), v.end());

    vector<bool> vis(n, false);

    int swaps = 0;

    for(int i = 0; i < n; i++) {

        // already correct
        if(vis[i] || v[i].second == i)
            continue;

        int cycle = 0;
        int j = i;

        while(!vis[j]) {
            vis[j] = true;
            j = v[j].second;
            cycle++;
        }

        swaps += (cycle - 1);
    }

    return swaps;
}
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int ans=0;
        while(!q.empty()){
           int n=q.size();
           vector<int>a;
           for(int i=0;i<n;i++){
           auto t=q.front();
           q.pop();
           a.push_back(t->val);
           if(t->left!=NULL) q.push(t->left);
           if(t->right!=NULL) q.push(t->right);
           }

           ans+=minSwaps(a);
        }

        return ans;
    }
};