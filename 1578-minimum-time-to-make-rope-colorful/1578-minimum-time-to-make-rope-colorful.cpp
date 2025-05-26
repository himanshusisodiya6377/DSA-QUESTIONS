class Solution {
public:
    void work(int &ans,int i,int j, vector<int>& neededTime){
        int sum=0;
        int maxi=INT_MIN;
        for(int k=i;k<=j;k++){
            sum+=neededTime[k];
            maxi=max(maxi,neededTime[k]);
        }
        ans+=sum-maxi;
    }
    int minCost(string colors, vector<int>& neededTime) {
        int n=neededTime.size();
        int ans=0;
        int i=0,j=1;
        while(j<n){
            if(colors[i]==colors[j]){
                j++;
            }
            else if(colors[i]!=colors[j] && i!=j-1){
                work(ans,i,j-1,neededTime);
                i=j;
                j++;
            }
            else{
                i++;
                j++;
            }
        }
        if(i<n-1) work(ans,i,j-1,neededTime);
        return ans;
    }
};