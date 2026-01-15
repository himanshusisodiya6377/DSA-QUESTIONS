class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int maxih=1;
        int maxiv=1;

        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());

        int len=1;
        for(int i=1;i<hBars.size();i++){
            if(hBars[i]==(hBars[i-1]+1)) len++;
            else len=1;
            maxih=max(maxih,len);
        }

        maxih++;
        
        // if(maxih==1) maxih++;
        // else maxih+=2;
        
        len=1;
         for(int i=1;i<vBars.size();i++){
            if(vBars[i]==(vBars[i-1]+1)) len++;
            else len=1;
            maxiv=max(maxiv,len);
        }

        maxiv++;

        // if(maxiv==1) maxiv++;
        // else maxiv+=2;

        int side=min(maxih,maxiv);

        return side*side;
        
    }
};