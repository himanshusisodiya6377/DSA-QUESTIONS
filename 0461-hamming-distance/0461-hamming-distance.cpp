class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans=0;

        while(x!=0 || y!=0){
            if((x&1)!=(y&1)) ans++;
            // cout<<x&1<<" "<<y&1<<endl;
            x=x>>1;
            y=y>>1;
            cout<<ans<<" "<<x<<" "<<y<<endl;
        }

        return ans;
    }
};