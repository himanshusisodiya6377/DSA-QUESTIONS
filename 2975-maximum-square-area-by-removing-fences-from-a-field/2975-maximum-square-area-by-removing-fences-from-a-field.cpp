class Solution {
public:
    int mod=1e9+7;
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        // if(n==m) return m*n;

        long long area=-1;

        vector<int>hf;
        hf.push_back(1);
        for(auto &it : hFences) hf.push_back(it);
        hf.push_back(m);

        vector<int>vf;
        vf.push_back(1);
        for(auto &it : vFences) vf.push_back(it);
        vf.push_back(n);

        sort(hf.begin(),hf.end());
        sort(vf.begin(),vf.end());
        

        // for(int i=0;i<hf.size();i++){
        //     for(int j=0;j<vf.size();j++){
        //         if(hf[i]-1==vf[j]-1){
        //         int a=(hf[i]-1)*(vf[j]-1);
        //         // cout<<i-1<<" "<<j-1<<endl;
        //         // cout<<a<<endl;
        //         area=max(area,a);
        //         }
        //     }
        // }
        unordered_set<int>h;
        unordered_set<int>v;

        for(int i=0;i<hf.size();i++){
            for(int j=i+1;j<hf.size();j++){
                int side=(hf[j]-1)-(hf[i]-1);
                h.insert(side);
                // cout<<side<<endl;
            }
        }

        for(int i=0;i<vf.size();i++){
            for(int j=i+1;j<vf.size();j++){
                int side=(vf[j]-1)-(vf[i]-1);
                // cout<<side<<endl;
                if(h.find(side)!=h.end()){
                    long long a=(1LL*(side)*(side));
                    // a=a%mod;
                    area=max(area,a);
                    // area=area%mod;
                }
                // cout<<side<<endl;
            }
        }

        return (area==-1 ? -1 : area%mod);
    }
};