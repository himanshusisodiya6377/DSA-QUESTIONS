class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n=people.size();
        int ans=0;
        // vector<int>v(n,false);
        sort(people.begin(),people.end());
        //tc-O(N^2) SC-O(N)
        // for(int i=0;i<n-1;i++){
        //     bool flag=false;
        //     for(int j=n-1;j>i;j--){
        //         if(people[i]+people[j]<=limit && (v[i]!=true && v[j]!=true)) {
        //             ans++;
        //             flag=true;
        //             v[i]=true;
        //             v[j]=true;
        //             break;
        //         }
        //     }
        //     if(flag==false && v[i]!=true) ans++;
        // }
        // if(v[n-1]==false) ans++;

        //OPTIMISE
        //TC-O(N) SC-O(1)
        int i=0,j=n-1;
        while(i<j){
            int sum=people[i]+people[j];
            // if(i==j){
            //     ans++;
            //     break;
            // }
            if(sum>limit){
                j--;
                ans++;
            }
            else{
                  i++;
                  j--;
                  ans++;
            }
        }
        if(i==j) ans++;
        return ans;
    }
};