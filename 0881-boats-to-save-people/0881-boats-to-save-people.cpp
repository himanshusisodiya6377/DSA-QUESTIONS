class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n=people.size();
        int ans=0;
        vector<int>v(n,false);
        sort(people.begin(),people.end());
        for(int i=0;i<n-1;i++){
            bool flag=false;
            for(int j=n-1;j>i;j--){
                if(people[i]+people[j]<=limit && (v[i]!=true && v[j]!=true)) {
                    ans++;
                    flag=true;
                    v[i]=true;
                    v[j]=true;
                    break;
                }
            }
            if(flag==false && v[i]!=true) ans++;
        }
        if(v[n-1]==false) ans++;
        return ans;
    }
};