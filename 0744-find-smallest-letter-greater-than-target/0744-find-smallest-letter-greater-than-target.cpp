class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ch=target;
        for(int i=0;i<letters.size();i++){
            if(letters[i]>ch){
                ch=letters[i];
                break;
            }
        }
        if(ch==target) return letters[0];
        else return ch;
    }
};