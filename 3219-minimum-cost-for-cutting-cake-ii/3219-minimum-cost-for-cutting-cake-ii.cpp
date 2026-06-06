class Solution {
public:
    typedef pair<int,char> p;
    long long minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        // sort(horizontalCut.rbegin(),horizontalCut.rend());
        // sort(verticalCut.rbegin(),verticalCut.rend());

        priority_queue<p>pq;

        for(auto &it : horizontalCut){
            pq.push({it,'h'});
        }

        for(auto &it : verticalCut){
            pq.push({it,'v'});
        }

        // int i=0,j=0;

        int hor_pic=1,vet_pic=1;
        long long ans=0;
        while(!pq.empty()){
             auto p=pq.top();
             pq.pop();
             if(p.second=='h'){
                ans+=p.first*vet_pic;
                hor_pic++;
             }
             else{
                ans+=p.first*hor_pic;
                vet_pic++;
             }
            //  cout<<ans<<endl;
        }
        
        return ans;
    }
};