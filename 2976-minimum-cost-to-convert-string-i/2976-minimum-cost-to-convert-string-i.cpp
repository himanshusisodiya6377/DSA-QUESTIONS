class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>>dist(27,vector<long long>(27,1e8));
        int n=original.size();
        for(int i=0;i<26;i++){
            dist[i][i]=0;
        }
        for(int i=0;i<n;i++){
             int u = original[i] - 'a';
            int v = changed[i] - 'a';
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }

        for(int k=0;k<26;k++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    if(dist[i][k]+dist[k][j]<dist[i][j]){
                        dist[i][j]=dist[i][k]+dist[k][j];
                    }
                }
            }
        }
        long long ans=0;
        for(int i=0;i<source.size();i++){
            if(source[i]==target[i]) continue;
            else if(dist[source[i]-'a'][target[i]-'a']==1e8) return -1;
            else{
                ans+=dist[source[i]-'a'][target[i]-'a'];
            }
        }
        return ans;
    }
};