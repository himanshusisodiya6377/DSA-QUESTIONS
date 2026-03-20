class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        
        int n=name.length();
        int m=typed.length();

        int i=0,j=0;

        while(i<n && j<m){
            //if matched
            while(i<n && j<m && name[i]==typed[j]){
                i++;
                j++;
            }

            //move j till you dont find name[i]
            while(j>0 && j<m && typed[j]==typed[j-1]) j++;

            if(i<n && j<m && name[i]!=typed[j]) return false;
            // if(i>=n && j<m) return false;
        }

        if(i>=n && j>=m) return true;
        return false;
    }
};