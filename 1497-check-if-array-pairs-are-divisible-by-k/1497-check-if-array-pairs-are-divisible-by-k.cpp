class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>v(k,0);
        // unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            v[((arr[i]%k)+k)%k]++;
        }
        if(v[0]%2!=0) return false;
        for(int i=1;i<=k/2;i++){
            if(v[i]!=v[k-i]) return false;
        }
        return true;
    }
};