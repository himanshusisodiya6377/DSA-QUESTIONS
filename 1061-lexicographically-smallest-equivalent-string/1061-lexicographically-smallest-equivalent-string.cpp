class Solution {
public:
    class DSU{
        public:
        vector<int>par;
        DSU(int n){
            par.resize(n,0);
            for(int i=0;i<n;i++){
                par[i]=i;
            }
        }

        int find(int x){
            if(par[x]==x) return par[x];
            return par[x]=find(par[x]);
        }

        void Union(int x,int y){
            int par_x=find(x);
            int par_y=find(y);

            if(par_x<par_y){
                par[par_y]=par_x;
            }
            else if(par_x>par_y){
                 par[par_x]=par_y;
            }
            else{
                return;
            }  
        }
    };
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n=s1.length();
        DSU ds(26);
        for(int i=0;i<n;i++){
             ds.Union(s1[i]-'a',s2[i]-'a');
        }
         
        for(int i=0;i<26;i++){
            cout<<i<<" "<<ds.par[i]<<endl;
        }
        string ans="";
        for(int i=0;i<baseStr.length();i++){
            // cout<<ds.par[baseStr[i]-'a']<<endl;
            // cout<<'a'+ds.par[baseStr[i]-'a']<<endl;
            char ch='a'+ds.find(baseStr[i]-'a');
            // cout<<ch<<endl;
        
            ans.push_back(ch);
        }

        return ans;
    }
};