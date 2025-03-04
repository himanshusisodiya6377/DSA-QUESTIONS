class Solution {
public:
    string intToRoman(int num) {
        vector<int>numb={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        vector<string>roman={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        string ans="";
        while(num>0){
           for(int i=0;i<numb.size();i++){
            if(numb[i]<=num){
                int count=num/numb[i];
                while(count>0){
                    ans+=roman[i];
                    count--;
                }
                num=num%numb[i];
            }
           }
        }
        return ans;
    }
};