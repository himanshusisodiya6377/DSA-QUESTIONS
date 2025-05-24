class Solution {
public:
    int countSeniors(vector<string>& details) {
        int n=details.size();
        int count=0;
        for(int i=0;i<n;i++){
            char fir=details[i][11];
            char sec=details[i][12];
            if((fir=='6' && sec>'0') || (fir>'6')) count++;
        }
        return count;
    }
};