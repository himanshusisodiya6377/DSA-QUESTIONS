//Counting Sort Does in O(N), and as constant extra space used so O(1)
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int maxx = *max_element(nums.begin(),nums.end());
        vector<int> sortArray(maxx+1,0);

        for( int i=0; i<nums.size(); i++ )
            sortArray[nums[i]]++;

        int j = maxx;
        for( int i=1; i<nums.size(); i+=2 ) 
        {
            while( sortArray[j] == 0 )
                j--;
            nums[i] = j;
            sortArray[j]--;
        }
        for( int i=0; i<nums.size(); i+=2 ) 
        {
            while( sortArray[j] == 0 )
                j--;
            nums[i] = j;
            sortArray[j]--;
        }
    }
};