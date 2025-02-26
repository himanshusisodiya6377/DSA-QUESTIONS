class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int c=l.size();
        vector<bool>ans;
        for(int i=0;i<c;i++){
            bool flag=false;
               vector<int>v(nums.begin()+l[i],nums.begin()+r[i]+1);
               sort(v.begin(),v.end());
               int size=r[i]-l[i]+1;
               int diff=v[1]-v[0];
               for(int i=2;i<size;i++){
                if(v[i]-v[i-1]!=diff){
                    ans.push_back(false);
                    flag=true;
                    break;
                }
               }
               if(flag==false) ans.push_back(true);
        }
        return ans;
    }
};