class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n=colors.size();
        int count=0;
        int var;
        // bool flag=false;
        for (int i = 0; i < n; i++) {
    bool isAlternating = true;

    for (int j = 0; j < k - 1; j++) {  // Check `k` elements starting from `i`
        int currIndex = (i + j) % n;  // Ensure circular behavior
        int nextIndex = (i + j + 1) % n;
        
        if (colors[currIndex] == colors[nextIndex]) {
            isAlternating = false;
            break;
        }
    }

    if (isAlternating){
        var=i;
        break;
    }
}
        // for(int i=0;i<n;i++){
        //     int r=(i+k-1);
        //   for(int j=i;j<r-2;j++){
        //      int ch=j%n;
        //     int m=(j+1)%n;
           
        //     if(colors[ch]==colors[m]) {
        //         flag=false;
        //         break;
        //     }
        //     else {
        //         flag=true;
        //     }
        //   }
        //   if(flag==true){
        //        var=i;
        //         break;
        //   } 
        // }
        for(int i=var;i<n;i++){
            int j=(i+k-1)%n;
            int p=(i+1)%n;
            int m;
            if(j==0){
                m=n-1;
            }
            else m=j-1;
            if(k%2==0){
                if(colors[i]!=colors[j] && colors[i]!=colors[p] && colors[j]!=colors[m]) count++;
            }
            else{
                 if(colors[i]==colors[j] && colors[i]!=colors[p] && colors[j]!=colors[m]) count++;
            }
        }
      return count;
    }
};