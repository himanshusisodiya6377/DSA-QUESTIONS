class Solution {
public:
    int ans=0;
    void solve(string &tiles,int idx,vector<bool>used){
        // if(idx>=tiles.size()) return ;

           ans++;
        for(int i=0;i<tiles.size();i++){
           
           if(used[i]) continue;

           if(i>0 && !used[i-1] && tiles[i]==tiles[i-1]) continue;

           used[i]=true;
           solve(tiles,idx+1,used);
           used[i]=false;
        }
    }
    int numTilePossibilities(string tiles) {
        vector<bool>used(tiles.size(),false);
        sort(tiles.begin(),tiles.end());
        solve(tiles,0,used);
        return ans-1;
    }
};