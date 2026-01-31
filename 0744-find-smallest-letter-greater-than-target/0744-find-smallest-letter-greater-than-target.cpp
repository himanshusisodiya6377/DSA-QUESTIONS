class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        //O(n)
        // char ch=target;
        // for(int i=0;i<letters.size();i++){
        //     if(letters[i]>ch){
        //         ch=letters[i];
        //         break;
        //     }
        // }
        // if(ch==target) return letters[0];
        // else return ch;
     //O(logn)
     int lo=0,hi=letters.size()-1;
     while(lo<=hi){
        int mid=(lo+hi)/2;
        if(letters[mid]>target) hi=mid-1;
        else if(letters[mid]<=target) lo=mid+1;
     }
     if(lo==letters.size()) return letters[0];
     else return letters[lo];
    }
};