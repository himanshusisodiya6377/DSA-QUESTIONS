class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        
        int n=num.size();
        int i=n-1;
        int carry=0;
        while(i>=0 && k>=0){
            int sum = (num[i]+k%10+carry);
            if(sum>=10) num[i]=sum%10;
            else num[i]=sum;
            
            carry=sum/10;
            i--;
            k/=10;
        }

        while(carry>0 || k>0){
            int sum = (k%10+carry);
            if(sum>=10) num.insert(num.begin(),sum%10);
            else num.insert(num.begin(),sum);
            carry=sum/10;
            k/=10;
            // num.insert(num.begin(),sum);
        }

        return num;
    }
};