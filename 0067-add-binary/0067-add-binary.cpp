class Solution {
public:
    string addBinary(string a, string b) {
        int n=a.length();
        int m=b.length();

        if(n<m) return addBinary(b,a);

        int i=n-1,j=m-1;
        int carry=0;

        while(i>=0 && j>=0){
            if(a[i]=='1' && b[j]=='1'){
                if(carry==0){
                a[i]='0';
                carry=1;
                }
                else{
                 carry=1;
                }
            }
            else{
                if(a[i]=='1' || b[j]=='1'){
                    if(carry>0){
                        a[i]='0';
                        carry=1;
                    }
                    else{
                        a[i]='1';
                    }
                }
                else{
                    if(carry>0){
                        a[i]='1';
                        carry=0;
                    }
                }
            }
            i--;
            j--;
        }   
        
        //if j end remaining i will work
        while(i>=0){
            if(a[i]=='0'){
                if(carry>0){
                    a[i]='1';
                    carry=0;
                }
            }
            else{
                if(carry>0){
                    a[i]='0';
                    carry=1;
                }
            }
            i--;
        }
         
        if(carry>0) a.insert(a.begin(),'1');
        return a;

    }
};