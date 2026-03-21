class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n=nums1.size();

        unordered_map<int,int>freq;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                freq[nums1[i]+nums2[j]]++;
            }
        }

        int cnt=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int sum=nums3[i]+nums4[j];
                cnt+=freq[-sum];
            }
        }

        return cnt;
    }
};