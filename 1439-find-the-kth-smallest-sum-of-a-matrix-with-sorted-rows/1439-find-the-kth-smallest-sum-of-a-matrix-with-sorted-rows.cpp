class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int C=min((int)mat[0].size(),k);

        priority_queue<int>maxi;
        maxi.push(0);

        for(auto &it : mat){

            priority_queue<int>next;
            while(!maxi.empty()){
            auto p=maxi.top();
            maxi.pop();
            
            for(int i=0;i<C;i++){
                next.push({p+it[i]});

                if(next.size()>k) next.pop();
            }
            }
            maxi=move(next);
        }

        return maxi.top();
    }
};