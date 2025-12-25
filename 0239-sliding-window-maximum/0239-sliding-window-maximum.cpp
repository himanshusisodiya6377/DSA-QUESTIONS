class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        deque<pair<int,int>>d;
        for(int i=0;i<k;i++){
            if(d.empty()) d.push_back({nums[i],i});
            else{
                while(!d.empty() && d.back().first<nums[i]) d.pop_back();
                // if(!d.empty() && d.back().first)
                // if(d.emprty())
                d.push_back({nums[i],i});
            }
        }
        int i=0,j=k-1;
        vector<int>ans;
        ans.push_back(d.front().first);
        while(j<n){
          while(!d.empty() && d.front().second<=i) d.pop_front();
          i++;
          j++;
          if(j>=n) break;
          while(!d.empty() && d.back().first<nums[j]) d.pop_back();
          d.push_back({nums[j],j});
          ans.push_back(d.front().first);
        }
        return ans;
    }
};