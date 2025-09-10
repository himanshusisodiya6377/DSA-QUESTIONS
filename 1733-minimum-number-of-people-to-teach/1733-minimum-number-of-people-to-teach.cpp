class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        unordered_set<int>sad;
        for(auto it : friendships){
            int u=it[0]-1;
            int v=it[1]-1;
            unordered_set<int>lang(begin(languages[u]),end(languages[u]));
            bool canTalk=false;
            for(auto x : languages[v]){
                if(lang.find(x)!=lang.end()){
                    canTalk=true;
                    break;
                }
            }
            if(!canTalk){
                 sad.insert(u);
                 sad.insert(v);
            }
        }
        int maxi=0;
        vector<int>langu(n+1,0);
        for(auto it : sad){
            for(auto x : languages[it]){
                  langu[x]++;
                  maxi=max(maxi,langu[x]);
            }
        }

        return sad.size()-maxi;
    }
};