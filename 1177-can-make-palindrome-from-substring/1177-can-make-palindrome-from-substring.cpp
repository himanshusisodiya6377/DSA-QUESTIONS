class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int q=queries.size();
        vector<bool>ans(q,false);

        int n=s.length();
        //storing each character freq in 2d map
        vector<vector<int>>freq(n,vector<int>(26,0));

        freq[0][s[0]-'a']++;
        
        //creat a prefix sum
        for(int i=1;i<n;i++){
           
           for(int j=0;j<26;j++){
            freq[i][j]=freq[i-1][j];
           }
           freq[i][s[i]-'a']=freq[i-1][s[i]-'a']+1;
        } 
        
        //go through queries
        for(int i=0;i<q;i++){
        int problem=0;
            int st=queries[i][0],end=queries[i][1],rep=queries[i][2];

            for(int j=0;j<26;j++){
                int cnt=freq[end][j]-(st>0 ? freq[st-1][j] : 0);
                // cout<<freq[end][j]<<endl;
                problem+=cnt%2;
            }

            // cout<<endl;
             
            if((problem)/2<=rep) ans[i]=true;
        }
        
        return ans;

    }
};