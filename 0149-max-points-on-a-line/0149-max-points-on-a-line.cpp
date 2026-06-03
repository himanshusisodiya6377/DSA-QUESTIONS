class Solution {
public:
    int gcd(int a,int b){
        if(b==0) return a;
        return gcd(b,a%b);
    }
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        int maxi=0;

        for(int i=0;i<n;i++){
            unordered_map<string,int>mp;
            int curr_max=0;

            for(int j=0;j<n;j++){
                
                if(i==j) continue;
                int dx=points[j][0]-points[i][0];
                int dy=points[j][1]-points[i][1];
                
                int gd=gcd(dx,dy);
                dx/=gd;
                dy/=gd;

                if(dx<0){
                    dx=-dx;
                    dy=-dy;
                }

                string s=to_string(dx)+"/"+to_string(dy);
                // cout<<s<<endl;
                mp[s]++;
                curr_max=max(curr_max,mp[s]);
            }
            maxi=max(maxi,curr_max);
        }
        return maxi+1;
    }
};