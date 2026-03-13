class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int n=hours.size();

        for(int i=0;i<n;i++){
            if(hours[i]>8) hours[i]=-1;
            else hours[i]=1;
        }

        int neg_idx=-1;

        int ans=INT_MIN;
        unordered_map<int,int>mp;

        int sum=0;
        for(int i=0;i<n;i++){
            sum+=hours[i];

            if(sum<0) ans=max(ans,i+1);
            else{
            //    for(int j=sum+1;j<=(i+1);j++){
                 if(mp.find(sum+1)!=mp.end()) {
                    ans=max(ans,i-mp[sum+1]);
                    // cout<<mp[j]<<" "<<i<<endl;
                 }
            //    }
            }
            
            if(mp.find(sum)==mp.end()) mp[sum]=i;
            // ans=max(ans,)
        }
        return (ans==INT_MIN ? 0 : ans);
    }
};