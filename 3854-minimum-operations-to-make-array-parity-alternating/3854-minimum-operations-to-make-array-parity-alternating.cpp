class Solution {
public:
    vector<int> makeParityAlternating(vector<int>& nums) {
        
        int n=nums.size();

        if(n==1) return {0,0};
        unordered_set<int> st(nums.begin() , nums.end());
        if(st.size() == 1){
            return {(int)n / 2 , 1};
        }
        
        //intially let first be even
        int cnt=0; //changes
        int diff=INT_MAX; //holding difference between minimum and maximum
        int maxi=INT_MIN;
        int mini=INT_MAX;

        bool flag=false; //have to be even if its true has to be even

        for(int i=0;i<n;i++){
            bool change=false;
            if(!flag && nums[i]%2!=0){
                cnt++;
                change=true;
                // maxi=max(maxi,nums[i]-1);
                // mini=min(mini,nums[i]+1);
            }
            else if(flag && nums[i]%2==0){
                cnt++;
                change=true;
                // maxi=max(maxi,nums[i]-1);
                // mini=min(mini,nums[i]+1);
            }

            maxi=max(maxi,(change ? nums[i]-1 : nums[i]));
            mini=min(mini,(change ? nums[i]+1 : nums[i]));

            flag=!flag;
            if(i>0) diff=maxi-mini;
            // cout<<diff<<endl;
        }

        vector<int>ans={cnt,diff};

          //intially let first be odd
        cnt=0; //changes
        diff=INT_MAX; //holding difference between minimum and maximum
        maxi=INT_MIN;
        mini=INT_MAX;

        flag=false; //have to be odd if its true has to be even

        for(int i=0;i<n;i++){
            bool change=false;
            if(!flag && nums[i]%2==0){
                cnt++;
                change=true;
                // maxi=max(maxi,nums[i]-1);
                // mini=min(mini,nums[i]+1);
            }
            else if(flag && nums[i]%2!=0){
                cnt++;
                change=true;
                // maxi=max(maxi,nums[i]-1);
                // mini=min(mini,nums[i]+1);
            }
            
            maxi=max(maxi,(change ? nums[i]-1 : nums[i]));
            mini=min(mini,(change ? nums[i]+1 : nums[i]));
            flag=!flag;
            if(i>0) diff=maxi-mini;
            // cout<<diff<<endl;
        }

        vector<int>res={cnt,diff};

         return min(ans,res);
    }
};