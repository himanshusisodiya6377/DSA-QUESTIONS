class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int n = colors.size();
        int count = 0;
        // int count0 = 0;
        // int count1 = 0;
        // bool flag=true;//for 010
        // for (int i = 0; i < 3; i++) {
        //     if (colors[i] == 0)
        //         count0++;
        //     else
        //         count1++;
        // }
        if(colors[0]==colors[2] && colors[0]!=colors[1]) count++;
        // if (count0 == 2 && count1 == 1)
        //     count++;
        // if (count0 == 1 && count1 == 2){
        //     flag=false;
        //     count++;
        // }
        for (int i = 1; i < n; i++) {
            int j = i + 2;
            j = j % n;
            int k=(i+1)%n;
            if(colors[i]==colors[j] && colors[i]!=colors[k]) count++;
            // if(flag==true){
            //     if(colors[j]==1){
            //         flag=false;
            //         count++;
            //     }
            // }
            // else{
            //     if(colors[j]==0){
            //         flag=true;
            //         count++;
            //     }
            // }
            // if (colors[i - 1] == 0 && colors[j] == 1) {
            //     count0--;
            //     count1++;
            // } else if (colors[i - 1] == 1 && colors[j] == 0) {
            //     count1--;
            //     count0++;
            // }
            // if (count0 == 2 && count1 == 1)
            //     count++;
            // if (count0 == 1 && count1 == 2)
            //     count++;
        }
    return count;
    }

};