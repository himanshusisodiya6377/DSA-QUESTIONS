class Solution {
public:
    long long mod=1000000007;
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int>pre_smaller(n,-1);
        vector<int>next_smaller(n,n);

        //conclude pre smaller
        stack<int>st;
        st.push(0);

        for(int i=1;i<n;i++){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(!st.empty()) pre_smaller[i]=st.top();
            st.push(i);
        }

        //conclude next smaller
        stack<int>s;
        s.push(n-1);

        for(int i=n-2;i>=0;i--){
            while(!s.empty() && arr[s.top()]>arr[i]){
                s.pop();
            }
            if(!s.empty()) next_smaller[i]=s.top();
            s.push(i);
        }
        
        // for(auto &it : pre_smaller) cout<<it<<" ";
        // cout<<endl;
        // for(auto &it : next_smaller) cout<<it<<" ";
        int ans=0;
        for(int i=0;i<n;i++){
            int left=0,right=0;
            if(pre_smaller[i]==-1){
               left=i+1;
            }
            else{
               left=i-pre_smaller[i];
            }

            if(next_smaller[i]==n){
               right=n-i;
            }
            else{
               right=next_smaller[i]-i;
            }
            int size=(((left)%mod)*((right)%mod))%mod;
            cout<<size<<endl;
            ans+=((size%mod)*(arr[i]%mod))%mod;
            ans=ans%mod;
        }
        return ans;
    }
};

/* 
Intuition
To arrive at the solution, we must track two things for each element arr[i]:

left[i]: the index of the first smaller element to the left of arr[i]
right[i]: the index of the first element that is less than or equal to arr[i] to the right
With left[i] and right[i] determined, the number of subarrays in which arr[i] is the minimum can be calculated by (1 + num_left) * (num_right + 1).
*/