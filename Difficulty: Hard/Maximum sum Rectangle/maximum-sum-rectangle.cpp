class Solution {
  public:
    int maxRectSum(vector<vector<int>> &matrix) {
        // code here
        int r=matrix.size();
        int c=matrix[0].size();

        unordered_map<int,int>mp;
        mp[0]=1;
        int ans=INT_MIN;

        vector<vector<int>>sum(r,vector<int>(c,0));

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                long long curr=matrix[i][j]+(i>0 ? sum[i-1][j] : 0);
                sum[i][j]=curr;
            }
        }
        for(int r1=0;r1<r;r1++){
            for(int r2=r1;r2<r;r2++){
                int curr=0;
                for(int j=0;j<c;j++){
                   curr+=(sum[r2][j]-(r1>0 ? sum[r1-1][j] : 0));
                //   cout<<r1<<" "<<r2<<" "<<j<<" "<<curr<<endl;

                //   if(mp.find(curr-target)!=mp.end()) ans+=mp[curr-target];
                //   mp[curr]++;
                 ans=max(ans,curr);
                 if(curr<0) curr=0;
                }

            }
        }

        return ans;
    }
};
