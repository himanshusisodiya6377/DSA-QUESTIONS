class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int white=0;
        int black=0;
        for(int i=0;i<k;i++){
            if(blocks[i]=='W') white++;
            else black++;
        }
        int count=white;
        int j=0;
        for(int i=k;i<blocks.length();i++){
            if(blocks[i]=='W'){
                white++;
            }
            else{
                black++;
            }
             if(blocks[j]=='W') white--;
                else black--;
                j++;
                if(count>white) count=white;
        }
        return count;
    }
};