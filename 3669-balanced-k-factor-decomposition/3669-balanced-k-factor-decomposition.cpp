class Solution {
public:
    vector<int>res;
    vector<int>curr;
    int diff=INT_MAX;
    void solve(int n,int k){
        if(k==1){
            curr.push_back(n);
            int maxi=*max_element(curr.begin(),curr.end());
            int mini=*min_element(curr.begin(),curr.end());
            int d=maxi-mini;
            if(d<diff){
                diff=d;
                res=curr;
            }
            curr.pop_back();
            return ;
        }

        for(int i=1;i<=n;i++){
            if(n%i==0){
            curr.push_back(i);
            solve(n/i,k-1);
            curr.pop_back();
            }
        }
    }
    vector<int> minDifference(int n, int k) {
        solve(n,k);
        return res;
    }
};