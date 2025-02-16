class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.size()==0) return {};
        if(nums.size()==1) return {to_string(nums[0])};
       long long i=0;
        long long end=-1;
       vector<string>v;
       for(int j=1;j<nums.size();j++){
        if(nums[j]!=(nums[j-1]+1)){
            if(j-1==i){
              v.push_back(to_string(nums[i]));
              i=j;
            } 
            else{
                v.push_back(to_string(nums[i]) + "->" + to_string(nums[j - 1]));
                i=j;
            }
        }
        end=j;
       }
       if(end==i) v.push_back(to_string(nums[i]));
       else  v.push_back(to_string(nums[i]) + "->" + to_string(nums[end]));
       return v;
    }
};