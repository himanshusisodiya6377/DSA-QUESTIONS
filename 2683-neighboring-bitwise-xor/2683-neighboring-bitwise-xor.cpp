class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int ans=0;
        for(int i=0;i<derived.size();i++){
            ans^=derived[i];
        }  
        if(ans==0) return true;
        else return false;
    }
};