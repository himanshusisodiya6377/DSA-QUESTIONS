class Solution {
public:
    bool check(vector<int>&bus,vector<int>&pass,int mid,int cap){
        int i=0,j=0;
        bool flag=false;
        while(i<bus.size() && j<pass.size()){
            int cnt=0;
            while(j<pass.size() && (pass[j]<=bus[i] || mid<=bus[i])){
                cnt++;
                if(pass[j]<=bus[i]) j++;
                else break;
            }

            if(cnt>cap){
                cnt-=cap;
                // if(flag) return false;
            }
            i++;
        }
        return j==pass.size();
    }
    int latestTimeCatchTheBus(vector<int>& bus, vector<int>& pass, int cap) {
        int n=bus.size();
        int m=pass.size();
        
        sort(bus.begin(),bus.end());
        sort(pass.begin(),pass.end());

        unordered_set<int>st;
        for(auto &it : pass) st.insert(it);

        int i=0,j=0;
        int board;
        int ans=0;
        for(int i=0;i<n;i++){
            board=0;
            while(j<pass.size() && pass[j]<=bus[i] && board<cap){
                j++;
                board++;
            }
        }

        if(board<cap){
            ans=bus.back();
        }
        else ans=pass[j-1];

        while(st.count(ans)) ans--;
        return ans;
    }
};