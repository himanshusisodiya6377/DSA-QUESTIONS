class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>s;
          unordered_map<int,int>freq;
        int n=arr.size();
        for(int i=0;i<n;i++){
            s[arr[i]]++;
        }
        for(auto p : s){
            freq[p.second]++;
        }
        for(auto p : freq){
            if(p.second>1) return false;
        }
        return true;
    }
};