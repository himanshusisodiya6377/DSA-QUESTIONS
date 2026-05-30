class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        multiset<int>st;
        for(auto &it : timePoints){
            // mp[stoi(it.substr(3,2))]++;
            int hour=stoi(it.substr(0,2));
            hour=hour*60;
            int minute=stoi(it.substr(3,2));
            st.insert(hour+minute);
            // cout<<hour+minute<<endl;
            // cout<<it.substr(3,2);
        }
        int diff=INT_MAX;
        int last=-1;
        for(auto &it : st){
                if(last==-1) last=it;
                else {
                    diff=min(diff,it-last);
                    last=it;
                }
                cout<<last<<endl;
        }

        diff=min(diff,abs(24*60-*st.rbegin()+*st.begin()));
        return diff;
    }
};