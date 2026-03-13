class Solution {
public:
    int longestAwesome(string s) {
        
        int n=s.length();
        int mask=0;

        unordered_map<int,int>mp; //holding mask
        mp[0]=-1;
        int ans=INT_MIN;

        for(int i=0;i<n;i++){
            
            // cout<<s[i]-'0'<<endl;
            mask=mask ^ (1<<(s[i]-'0'));
            
            //check if similar find anyway
            if(mp.find(mask)!=mp.end()){
                ans=max(ans,i-mp[mask]);
            }

            //go for each one bit

            for(int j=0;j<=9;j++){
                int temp=mask ^ (1<<j);
                if(mp.find(temp)!=mp.end()){
                    ans=max(ans,i-mp[temp]);
                }
            }

            if(mp.find(mask)==mp.end()) mp[mask]=i; 
        }
        return ans;
    }
};