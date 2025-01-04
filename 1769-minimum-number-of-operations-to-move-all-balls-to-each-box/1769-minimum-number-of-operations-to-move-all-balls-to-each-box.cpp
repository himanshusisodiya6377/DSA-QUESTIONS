class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size();
        vector<int>pre(n,0);
        vector<int>suff(n,0);
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(boxes[j]=='1'){
                    pre[i]+=abs(j-i);
                }
            }
        }
        for(int i=n-1;i>=1;i--){
            for(int j=i-1;j>=0;j--){
                if(boxes[j]=='1'){
                    suff[i]+=abs(j-i);
                }
            }
        }
         for(int i=0;i<n;i++) pre[i]+=suff[i];
         return pre;
    }
};