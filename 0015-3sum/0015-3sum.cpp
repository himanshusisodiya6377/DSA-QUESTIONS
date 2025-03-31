class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>fq;
        set<vector<int>>st;
        vector<vector<int>>ans;
        for(int i=0;i<n;i++) fq[nums[i]]++;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                vector<int>v;
                int x=nums[i]+nums[j];
                int get=-(x);
                if(j!=i+1 && nums[j]==nums[j-1]) continue;
                if(get!=nums[i] && get!=nums[j]){
                    if(fq.find(get)!=fq.end()){
                     v.push_back(nums[i]);
                     v.push_back(nums[j]);
                     v.push_back(get);
                     sort(begin(v),end(v));
                     st.insert(v);
                    }
                }
                else if(fq.find(get)!=fq.end() && ((get==nums[i] && get!=nums[j]) ||  (get!=nums[i] && get==nums[j]))  && fq[get]>1){
                     v.push_back(nums[i]);
                     v.push_back(nums[j]);
                     v.push_back(get);
                     sort(begin(v),end(v));
                       st.insert(v);
                }
                else{
                    if(fq.find(get)!=fq.end() && (get==nums[i] && get==nums[j]) && fq[get]>2){
                     v.push_back(nums[i]);
                     v.push_back(nums[j]);
                     v.push_back(get);
                     sort(begin(v),end(v));
                       st.insert(v);
                }
                }
            }
        }
        for(auto c : st){
            ans.push_back(c);
        }
        return ans;
    }
};