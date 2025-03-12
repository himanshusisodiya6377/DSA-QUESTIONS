class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
     int n=intervals.size();
     int i=0,j=1;
     int count=0;
     //imp 
     sort(begin(intervals),end(intervals));//sort according to first value
     while(j<n){
        vector<int>first=intervals[i];
        vector<int>second=intervals[j];

        int cf=first[0];
        int ce=first[1];
        int bf=second[0];
        int be=second[1];
        if(ce<=bf){//no overlapping
        i=j;
        j++;
        }
        else if(ce<=be){//overlapping
             j++;
             count++;
        }
        else if(ce>be){//overlapping 
            i=j;
            j++;
            count++;
        }
     }   
    return count;
    }
};