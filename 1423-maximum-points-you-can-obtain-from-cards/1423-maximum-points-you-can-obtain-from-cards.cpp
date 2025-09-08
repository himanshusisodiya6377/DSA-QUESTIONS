class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
       vector<int>temp=cardPoints;
       for(int i=0;i<cardPoints.size();i++) temp.push_back(cardPoints[i]);
       int sum=0;
       int maxi=INT_MIN;
       int n=cardPoints.size();
       int idx=n-k; 
       //intial sum
       for(int i=idx;i<n;i++){
        sum+=cardPoints[i];
       }
       maxi=max(maxi,sum);

       int m=temp.size();
       int i=idx+1,j=n;
       while(i<=n){
        sum-=temp[i-1];
        sum+=temp[j];
        maxi=max(maxi,sum);
        i++;
        j++;
       }
       return maxi;
    }
};