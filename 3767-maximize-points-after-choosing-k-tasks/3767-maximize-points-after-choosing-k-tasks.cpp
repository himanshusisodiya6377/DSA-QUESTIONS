class Solution {
public:
    long long maxPoints(vector<int>& technique1, vector<int>& technique2, int k) {
        vector<tuple<int,int,int>>v;

        int n=technique1.size();

        for(int i=n-1;i>=0;i--){
            v.push_back({technique1[i]-technique2[i],technique1[i],technique2[i]}); 
       }

       sort(v.begin(),v.end());

       long long ans=0;

       for(int i=n-1;i>=0;i--){
        if(k>0){
            ans+=get<1>(v[i]);
            k--;
        }
        else{
            if(get<0>(v[i])>=0){
                ans+=get<1>(v[i]);
            }
            else ans+=get<2>(v[i]);
        }
       }
       return ans;
    }
};