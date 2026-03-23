class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n=nums1.size();
        if(n==1) return true;


        unordered_set<int>mp;
        vector<int>odd,even;

        sort(nums1.begin(),nums1.end());

        for(auto &it : nums1){
            if(it%2==0) even.push_back(it);
            else odd.push_back(it);

            mp.insert(it);
        }

        // sort(odd.begin(),odd.end());
        // sort(even.begin(),even.end());

        if(odd.size()==0 || even.size()==0) return true;

        //check for even 
        bool flag1=true;
        for(auto &it : nums1){
            if(it%2!=0){
                auto i=upper_bound(odd.begin(),odd.end(),it-1)-odd.begin();
                // cout<<i-odd.begin()<<endl;
                if(i==odd.size() || odd[i]>=it) i--;
                // i--;
                // cout<<i<<endl;
                if(i<0 || odd[i]>=it){
                    flag1=false;
                    break;
                }
            }
        }
        // cout<<flag1<<endl;
        bool flag2=true;
        //check for odd
        for(auto &it : nums1){
            if(it%2==0){
                auto i=lower_bound(odd.begin(),odd.end(),it-1)-odd.begin();
                // cout<<i-odd.begin()<<endl;
                if(i==odd.size() || odd[i]>=it) i--;
                // cout<<i<<endl;
                if(i<0 || odd[i]>=it){
                    flag2=false;
                    break;
                }
            }
        }

        // cout<<flag2<<endl;

        if(flag1 || flag2) return true;

        return false;
    }
};