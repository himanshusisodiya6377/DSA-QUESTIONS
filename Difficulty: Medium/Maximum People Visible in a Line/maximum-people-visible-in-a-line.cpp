class Solution {
  public:
    int maxPeople(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<int>pre(n,0);
        
        stack<pair<int,int>>st; //val idx
        
        for(int i=0;i<n;i++){
            int cnt=0;
            while(!st.empty() && st.top().first<arr[i]){
                cnt+=(pre[st.top().second]+1);
                st.pop();
            }
            pre[i]=cnt;
            st.push({arr[i],i});
        }
        
        vector<int>suff(n,0);
        
        stack<pair<int,int>>s; //val idx
        
        for(int i=n-1;i>=0;i--){
            int cnt=0;
            while(!s.empty() && s.top().first<arr[i]){
                cnt+=(suff[s.top().second]+1);
                s.pop();
            }
            suff[i]=cnt;
            s.push({arr[i],i});
        }
        
        // for(int i=0;i<n;i++) cout<<pre[i]<<" ";
        // cout<<endl;
        // for(int i=0;i<n;i++) cout<<suff[i]<<" ";
        // cout<<endl;
        int maxi=INT_MIN;
        
        for(int i=0;i<n;i++) maxi=max(maxi,pre[i]+suff[i]+1);
        
        return maxi;
    }
};