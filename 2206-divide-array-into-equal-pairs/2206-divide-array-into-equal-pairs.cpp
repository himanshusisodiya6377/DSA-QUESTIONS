class Solution {
public:
    bool divideArray(vector<int>& nums) {
     int n=nums.size();
     if(n%2!=0) return false;
     unordered_map<int,int>mp;
     for(int i=0;i<n;i++) mp[nums[i]]++;
     for(auto p : mp){
        int x=p.second;
        if(x%2!=0) return false;
     }
     return true;
    //  int x=nums[0];
    //  for(int i=1;i<n;i++) x^=nums[i];
    //  if(x==0) return true;
    //  else return false;   
    }
};