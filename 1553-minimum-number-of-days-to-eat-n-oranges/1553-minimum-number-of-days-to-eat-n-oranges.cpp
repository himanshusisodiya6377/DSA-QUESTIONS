class Solution {
public:
    int minDays(int n) {
        
        unordered_set<int>st;
        queue<int>q;
        q.push(n);
        // st.insert(n);
        int ans=0;

        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto p=q.front();
                q.pop();

                // int val=p.first;
                // int move=p.second;

                if(p==0) return ans;
                // if(st.count(p)) continue;

                //can decrease by one
                if(!st.count(p-1)){
                q.push(p-1);
                st.insert(p-1);
                }

                //can make half if even
                if(p%2==0 && !st.count(p/2)) {
                    q.push(p/2);
                    st.insert(p/2);
                }
                if(p%3==0 && p>= (2*(p/3)) && !st.count(p-(2*(p/3)))) {
                    q.push(p-(2*(p/3)));
                    st.insert(p-(2*(p/3)));
                }
            }
            ans++;
        }

        return -1;
    }
};