class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int h=abs(fx-sx);
        int v=abs(fy-sy);
        int min_time=max(h,v);
        if(h==0 && v==0 && t==1) return false;
        if(t>=min_time) return true;
        return false;
    }
};