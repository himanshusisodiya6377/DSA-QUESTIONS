class Solution {
  public:
    int minMen(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<pair<int,int>>v;
        
        for(int i=0;i<n;i++){
            if(arr[i]==-1) continue;
            else{
                v.push_back({max(0,i-arr[i]),min(i+arr[i],n-1)});
            }
        }
        
        sort(v.begin(),v.end());
        
        int i=0,cnt=0,curr_end=0;
        
        while(curr_end<n){
            int far=curr_end;
            
            while(i<v.size() && v[i].first<=curr_end){
                far=max(far,v[i].second+1);
                i++;
            }
            
            if(far==curr_end) return -1;
            
            cnt++;
            curr_end=far;
        }
        
        return cnt;
    }
};