class Solution {
public:
    // vector<vector<int>>points;
    class DSU{
       public:
       vector<int>parent;
       vector<int>size;
       

       DSU(int n){
        parent.resize(n,0);
        size.resize(n,1);

        for(int i=0;i<n;i++){
           parent[i]=i;
        }
       }

        int find(int x){
            if(parent[x]==x) return parent[x];
            return parent[x]=find(parent[x]);
        }

        void Union(int x,int y){
            auto p=find(x);
            auto q=find(y);

            if(p==q) return;

            if(size[p]<size[q]){
                parent[p]=q;
                size[q]+=size[p];
            }
            else{
                parent[q]=p;
                size[p]+=size[q];
            }
       }
    };
    int maxActivated(vector<vector<int>>& points) {
        // points=points;
        unordered_map<int,vector<int>>mpx;
        unordered_map<int,vector<int>>mpy;

        for(int i=0;i<points.size();i++){
            mpx[points[i][0]].push_back(i);
        }
         for(int i=0;i<points.size();i++){
            mpy[points[i][1]].push_back(i);
        }

        DSU ds(points.size());


        for(auto &it : mpx){
             for(int i=0;i<it.second.size()-1;i++){
                ds.Union(it.second[i],it.second[i+1]);
             }
        }

        for(auto &it : mpy){
             for(int i=0;i<it.second.size()-1;i++){
                ds.Union(it.second[i],it.second[i+1]);
             }
        }

        // for(int i=0;i<points.size();i++) cout<<ds.size[i]<<" ";

        int ans=0;
        priority_queue<int>pq;
        unordered_set<int>st;

        for(int i=0;i<points.size();i++){
            int par=ds.find(i);
            if(!st.count(par)) pq.push(ds.size[par]);
            st.insert(par);
        }

        // sort(ds.size.begin(),ds.size.end());
        // for(int i=points.size()-1;i>min(points.size()-3,ds.size.size());i--){
        //     ans+=ds.size[i];
        //     cout<<ans<<endl;
        // }
        int k=2;

        while(!pq.empty() && k>0){
            ans+=pq.top();
            // cout<<ans<<endl;
            k--;
            pq.pop();
        }

        return ans+1;
    }
};