class Solution {
public:
   int minSwaps(vector<int>& arr) {
   int n=arr.size();

   vector<pair<int,int>>v;

   for(int i=0;i<n;i++){
    v.push_back({arr[i],i});
   }
   int swp=0;
   sort(v.begin(),v.end());

   vector<bool>vis(n,false);

   for(int i=0;i<n;i++){
    if(vis[i]==true || v[i].second==i) continue;
    int cyc=0;
    int j=i;

    while(!vis[j]){
        vis[j]=true;
        j=v[j].second;
        cyc++;
    }
    swp+=cyc-1;
   }

   return swp;
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