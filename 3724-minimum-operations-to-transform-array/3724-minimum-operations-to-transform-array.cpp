class Solution {
public:
    typedef long long ll;
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        ll n=nums1.size();
        ll m=nums2.size();
        ll num=-1,diff=INT_MAX;
        ll ans=0;
        ll chk=nums2[m-1];
        for(int i=0;i<n;i++){
            ll d=abs(chk-nums1[i]);
            if(d<diff){
                diff=d;
                num=nums1[i];
            }
        }
    //    cout<<num<<" "<<diff;
        //now ans calculation
        for(int i=0;i<n;i++){
            ll fir=nums1[i];
            ll sec=nums2[i];
            if(diff!=0){
              if(fir<=sec && (chk>=fir && chk<=sec)){
                diff=0;
                ans+=abs(nums2[i]-nums1[i]);
              }
              else if(fir>sec && (chk<=fir && chk>=sec)){
                diff=0;
                ans+=abs(nums2[i]-nums1[i]);
              }
              else{
                ll d=abs(chk-sec);
                if(d<diff){
                    diff=d;
                    num=nums2[i];
                }
                ans+=abs(nums2[i]-nums1[i]);
              }
            }
            else ans+=abs(nums2[i]-nums1[i]);
        }
        ans+=diff+1;
        return ans;
    }
};