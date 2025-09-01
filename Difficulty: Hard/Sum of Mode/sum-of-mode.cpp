class Solution {
public:
    struct cmp {
        bool operator()(const pair<int,int>& a, const pair<int,int>& b) const {
            if(a.second == b.second) 
                return a.first < b.first;   // smaller element first if freq same
            return a.second > b.second;     // higher freq first
        }
    };
    
    int sumOfModes(vector<int>& arr, int k) {
        int n = arr.size();
        
        unordered_map<int,int> freq;          // element -> frequency
        set<pair<int,int>, cmp> st;          // ordered by (freq desc, value asc)
        
        for(int i=0;i<k;i++){
            freq[arr[i]]++;
        }
        for(auto &p : freq){
            st.insert({p.first, p.second});
        }
        
        int sum=0;
        int i=0, j=k-1;
        
        while(j < n){
            // take mode (first element in set)
            auto mode = *st.begin();
            sum += mode.first;  // add the element (not freq, assuming that's what you mean)
            
            // slide window
            int elemOut = arr[i];
            st.erase({elemOut, freq[elemOut]});
            freq[elemOut]--;
            if(freq[elemOut] > 0)
                st.insert({elemOut, freq[elemOut]});
            
            i++;
            j++;
            if(j < n){
                int elemIn = arr[j];
                if(freq[elemIn] > 0)
                    st.erase({elemIn, freq[elemIn]});
                freq[elemIn]++;
                st.insert({elemIn, freq[elemIn]});
            }
        }
        
        return sum;
    }
};
