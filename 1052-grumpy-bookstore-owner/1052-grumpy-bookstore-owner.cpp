class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n=customers.size();
        int sum=0;
        for(int i=0;i<n;i++){
            if(grumpy[i]==0) sum+=customers[i];
        }
        for(int i=0;i<minutes;i++){
            if(grumpy[i]==1) sum+=customers[i];
        }
        int i=0,j=minutes-1;
        int maxi=0;
          maxi=max(maxi,sum);
        while(j<n){
         i++;
         j++;
        if(j<n) if(grumpy[j]==1) sum+=customers[j];
                if(grumpy[i-1]==1) sum-=customers[i-1];
         maxi=max(maxi,sum);
        }
        return maxi;
    }
};