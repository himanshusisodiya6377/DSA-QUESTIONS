class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        
        int r=matrix.size();
        int c=matrix[0].size();

        unordered_map<int,int>mp;
        mp[0]=1;
        int ans=0;

        vector<vector<int>>sum(r,vector<int>(c,0));

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                
                long long curr=matrix[i][j]+(i>0 ? sum[i-1][j] : 0)+(j>0 ? sum[i][j-1] : 0)-(i>0 && j>0 ? sum[i-1][j-1] : 0);
                sum[i][j]=curr;
            }
        }

        // for(int i=0;i<r;i++){
        //     for(int j=0;j<c;j++){
        //         cout<<sum[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        for(int r1=0;r1<r;r1++){
            for(int r2=r1;r2<r;r2++){

                for(int c1=0;c1<c;c1++){
                    for(int c2=c1;c2<c;c2++){
                       
                       long long curr=sum[r2][c2]-(r1>0 ? sum[r1-1][c2] : 0)-(c1>0 ? sum[r2][c1-1] : 0)+ (r1>0 && c1>0 ? sum[r1-1][c1-1] : 0);
                    //    cout<<r1<<" "<<c1<<" "<<r2<<" "<<c2<<" "<<curr<<endl;
                       if(curr==target) ans++;

                    //    mp[curr]++;

                    }
                }
            }
        }

        return ans;
    }
};