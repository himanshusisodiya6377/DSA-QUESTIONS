class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n=skill.size();
        int count=n/2;
        long long ans=0;
        sort(begin(skill),end(skill));
        int i=1,j=n-2;
        int sum=skill[0]+skill[n-1];
        count--;
        ans+=(skill[0]*skill[n-1]);
        while(i<j){
            ans+=(skill[i]*skill[j]);
            int get=skill[i]+skill[j];
            if(get==sum){
                i++;
                j--;
                count--;
            } 
            else break;
        }
        if(count>0) return -1;
        else return ans;
    }
};