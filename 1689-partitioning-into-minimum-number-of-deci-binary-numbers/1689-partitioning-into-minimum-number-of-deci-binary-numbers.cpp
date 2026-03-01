class Solution {
public:
    int minPartitions(string n) {
        int x;
        int maxi=INT_MIN;
        int k=n.length();
        for(int i=0;i<k;i++){
            x=(n[i])-48;
            if(x>maxi)  maxi=x;
        }
        return maxi;
    }
};