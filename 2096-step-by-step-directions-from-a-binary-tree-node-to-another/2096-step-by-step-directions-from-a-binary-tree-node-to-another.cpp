class Solution {
public:
/*
🌳 Why there is ONLY ONE WAY in a tree
🔑 Definition of a tree

A tree is a connected graph with no cycles.

That gives us two critical properties:

There is exactly one simple path between any two nodes

No alternative routes exist

So between startValue and destValue:

✔️ There is exactly ONE path
*/
    void creat_graph(TreeNode*root,unordered_map<int,vector<pair<int,char>>>&adj){
             if(root==NULL) return;
             if(root->left) {
                adj[root->val].push_back({root->left->val,'L'});
                adj[root->left->val].push_back({root->val,'U'});
                creat_graph(root->left,adj);
             }
             if(root->right) {
                adj[root->val].push_back({root->right->val,'R'});
                adj[root->right->val].push_back({root->val,'U'});
                creat_graph(root->right,adj);
             }

    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
         unordered_map<int,vector<pair<int,char>>>adj;
         creat_graph(root,adj);  
         queue<int>q;

         q.push({startValue});

         unordered_set<int>st;
         st.insert(startValue);

         unordered_map<int,pair<int,char>>mp;

         while(!q.empty()){
            auto p=q.front();
            q.pop();

            int root_val=p;
            // string s=p.second;

            st.insert(root_val);

            if(root_val==destValue){
                  break;
            }

            for(auto it : adj[root_val]){
                int v=it.first;
                char dir=it.second;
                if(st.find(v)==st.end()){
                   q.push(v);
                   st.insert(v);
                   mp[v]={root_val,dir};
                }
            }
         }
         
         string s="";
         int curr=destValue;

         while(curr!=startValue){
            s.push_back(mp[curr].second);
            curr=mp[curr].first;
         }

         reverse(s.begin(),s.end());
         return s;  
    }
};