class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n=asteroids.size();
        stack<int>st;
        for(int i=0;i<n;i++){
           if(st.size()==0) st.push(asteroids[i]);
           else if(st.top()>0 && asteroids[i]>0) st.push(asteroids[i]);
           else if(st.top()<0 && asteroids[i]<0) st.push(asteroids[i]);
           else if(st.top()<0 && asteroids[i]>0) st.push(asteroids[i]);
           else{
            if(st.top()>abs(asteroids[i])) continue;
            else{
                while(st.size()>0){
                    if(st.top()>0 && st.top()<abs(asteroids[i])) st.pop();
                    else if(st.top()>0 && st.top()==abs(asteroids[i])) {
                        st.pop();
                        break;
                    }
                    else if(st.top()>0 && st.top()>abs(asteroids[i])) break;
                    else{
                        st.push(asteroids[i]);
                        break;
                    }
                }
            }
           }
        }
        vector<int>ans;
        while(st.size()>0){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};