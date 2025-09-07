class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>ans;
        if(n%2==0){
            int num=-1;
            for(int i=0;i<n/2;i++){
                ans.push_back(num);
                num--;
            }
            num=1;
            for(int i=n/2;i<n;i++){
                ans.push_back(num);
                num++;
            }
        }
        else{
              int num=-1;
            for(int i=0;i<n/2;i++){
                ans.push_back(num);
                num--;
            }
            ans.push_back(0);
            num=1;
            for(int i=n/2;i<n-1;i++){
                ans.push_back(num);
                num++;
            }
        }
        return ans;
    }
};