class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        // write code here
        deque<pair<int,int>>d;
        vector<int>ans;
        int i=0,j=0;
        int n=arr.size();
        while(j<n){
            if(arr[j]<0)
            d.push_back({arr[j],j});
            while(!d.empty() && d.front().second<i) d.pop_front();
            
            if(j-i+1==k){
                if(!d.empty()) ans.push_back(d.front().first);
                else ans.push_back(0);
                i++;
            }
            j++;
        }
        return ans;
    }
};