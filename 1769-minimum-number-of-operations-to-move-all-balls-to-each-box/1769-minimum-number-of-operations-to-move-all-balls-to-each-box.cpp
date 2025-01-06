class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size();
        vector<int>pre(n,0);
        
        // vector<int>suff(n,0);
        // for(int i=0;i<n-1;i++){
        //     for(int j=i+1;j<n;j++){
        //         if(boxes[j]=='1'){
        //             pre[i]+=abs(j-i);
        //         }
        //     }
        // }
        //optimise
        int one=boxes[0]=='1';
        
        for(int i=1;i<n;i++){//prefix sum calculation
             pre[i]=pre[i-1]+one;
             if(boxes[i]=='1') one++;
        }
        one=0;
        int prev=0;
        for(int i=n-1;i>=0;i--){//suffix sum add in prefix 
            pre[i]=pre[i]+prev;
            if(boxes[i]=='1') one++;
            prev+=one;
        }
        //  for(int i=0;i<n;i++) pre[i]+=suff[i];
         return pre;
    }
};