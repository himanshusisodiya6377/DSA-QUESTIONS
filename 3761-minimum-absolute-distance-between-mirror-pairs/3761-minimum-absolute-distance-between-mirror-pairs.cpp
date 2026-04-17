class Solution {
public:
    bool check(int i,int j){
        string s=to_string(i);
        // cout<<s<<endl;
        reverse(s.begin(),s.end());
        // cout<<stoi(s)<<endl;
        // string t=to_string(j);
       // cout<<t<<endl;
        // reverse(t.begin(),t.end());
        return stoi(s)==j;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        int n=nums.size();
        // int i=0,j=1;
        int ans=INT_MAX;
        // while(i<n){
        //     while(j<n){
        //     if(check(nums[i],nums[j])){
        //         ans=min(ans,abs(i-j));
        //         // cout<<ans<<endl;
        //         break;
        //     }
        //     else{
        //         j++;
        //     }
        //     }
        //     i++;
        //     j=i+1;
        // }
        unordered_map<int,vector<int>>mp;
        unordered_map<int,vector<int>>pos;

        for(int i=0;i<nums.size();i++) pos[nums[i]].push_back(i);
        for(int i=0;i<nums.size();i++){
            string s=to_string(nums[i]);
            reverse(s.begin(),s.end());
            if(pos.find(stoi(s))!=pos.end()){
                vector<int>&temp=pos[stoi(s)];
                 if(temp[0]!=i && temp[0]>i) ans=min(ans,abs(i-temp[0]));
                else if(temp.size()>1 && temp[1]>i) ans=min(ans,abs(i-temp[1]));
            }
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};