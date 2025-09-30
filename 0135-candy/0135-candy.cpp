class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        if(n==1) return 1;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        unordered_map<int,int>candy;
        // unordered_map<int,int>rate;

        // creating require database
        for(int i=0;i<n;i++){
            pq.push({ratings[i],i});
            candy[i]=1;
            // rate[i]=ratings[i];
        }

        int mini=pq.top().second;

        int ans=0;

        while(!pq.empty()){
            pair<int,int>p=pq.top();
            pq.pop();
            int idx=p.second;
            if(idx==0){
                if(ratings[idx+1]<ratings[idx]){
                    candy[idx]=candy[idx+1]+1;
                    ans+=candy[idx];
                }
                else ans+=candy[idx];
            }
            else if(idx==n-1){
                if(ratings[idx-1]<ratings[idx]){
                    candy[idx]=candy[idx-1]+1;
                     ans+=candy[idx];
                }
                else ans+=candy[idx];
            }
            else{
                if(ratings[idx-1]<ratings[idx] && ratings[idx+1]<ratings[idx]){
                    candy[idx]=max(candy[idx-1],candy[idx+1])+1;
                     ans+=candy[idx];
                }
                else if(ratings[idx-1]<ratings[idx]){
                    candy[idx]=candy[idx-1]+1;
                     ans+=candy[idx];
                }
                else if(ratings[idx+1]<ratings[idx]){
                    candy[idx]=candy[idx+1]+1;
                     ans+=candy[idx];
                }
                else ans+=candy[idx];
            }
        }
        // ans+=candy[mini];
         return ans;
    }
};