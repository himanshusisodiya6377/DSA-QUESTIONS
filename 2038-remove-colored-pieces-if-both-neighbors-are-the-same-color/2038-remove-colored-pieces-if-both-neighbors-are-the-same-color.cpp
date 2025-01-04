class Solution {
public:
    bool winnerOfGame(string colors) {
           int n=colors.length();
        int countA=0;
        int countB=0;
        int count=0;
        int temp=0;
        for(int i=0;i<n;i++){//for triple pair of A
             if(colors[i]=='A') count++;
             else{
                temp=count;
                count=0;
             }
             if(temp>=3){
                int x=temp-2;
                countA+=x;
             }
        }
        if(count>=3) {
            int x=count-2;
                countA+=x;
        }
        count=0;
        temp=0;
            for(int i=0;i<n;i++){//for triple pair of B
              if(colors[i]=='B') count++;
             else{
                temp=count;
                count=0;
             }
             if(temp>=3){
                int x=temp-2;
                countB+=x;
             }
        }
          if(count>=3) {
            int x=count-2;
                countB+=x;
        }
        if(countA>countB) return true;
        else return false;
        // int i=0;
        // stack<char>st;
        // stack<char>temp;
        // for(int i=n-1;i>=0;i--) st.push(colors[i]);
        // while(i<n){
        //     int count=0;
        //     if(i%2==0){
        //         while(st.size()>0 && count<3){
        //             char ch=st.top();
        //             if(ch=='A') count++;
        //             else count=0;
        //             temp.push(ch);
        //             st.pop();
        //         }
        //         if(count==3) temp.pop();
        //         else return false;
        //     }
        //     else{
        //          while(st.size()>0 && count<3){
        //             char ch=st.top();
        //             if(ch=='B') count++;
        //             else count=0;
        //             temp.push(ch);
        //             st.pop();
        //         }
        //         if(count==3) temp.pop();
        //         else return true;
        //     }
        //     while(temp.size()>0){
        //              char ch=temp.top();
        //             st.push(ch);
        //             temp.pop();
        //         }
        //     i++;
        // }
        // return false;
    }
};