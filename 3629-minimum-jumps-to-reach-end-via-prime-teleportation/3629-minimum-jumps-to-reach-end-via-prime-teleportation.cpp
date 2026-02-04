class Solution {
public:
    bool prime(int x){
        for(int i=2;i*i<=x;i++){
            if(x%i==0) return false;
        }
        return true;
    }
    int minJumps(vector<int>& nums) {
        int n=nums.size();

        unordered_map<int,vector<int>>mp;

        for(int i=0;i<n;i++){
            int x=nums[i];

            for(int j=2;j*j<=x;j++){
                if(!prime(j)) continue; 
                
                if(x%j==0){
                mp[j].push_back(i);
                while(x%j==0) x/=j;
                }
            }

            if(x>1) mp[x].push_back(i);
        }    

        vector<bool> visit(n, false);   //handle visit
        //as there is chance we can go from prime to adjacent or to another divisible so we need to maintain another data structure for primes
        unordered_set<int>cnt;

        queue<pair<int,int>>q; //moves with index
        q.push({0,0});
        visit[0]=true;

        while(!q.empty()){
            auto p=q.front();
            q.pop();

            int moves=p.first;
            int idx=p.second;

            if(idx==n-1) return moves;

            //if its prime
            if(prime(nums[idx])){
                if(cnt.find(nums[idx])==cnt.end()){
                    cnt.insert(nums[idx]);
                    for(auto &it : mp[nums[idx]]){
                        if(!visit[it]){
                        visit[it]=true;
                        q.push({moves+1,it});
                        }
                    }
                }
            }

            if(idx-1>=0){
                if(!visit[idx-1]){
                    visit[idx-1]=true;
                    q.push({moves+1,idx-1});
                }
            }

            if(idx+1<n){
                if(!visit[idx+1]){
                    visit[idx+1]=true;
                    q.push({moves+1,idx+1});
                }
            }
        }

        return -1;
    }
};