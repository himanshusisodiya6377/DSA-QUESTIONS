/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long long lo=1,hi=n;
        while(lo<=hi){
            long long mid=(lo+hi)/2;
            int x=guess(mid);
            if(x==0) return mid;
            else if(x==1) lo=mid+1;
            else hi=mid-1;
        }
        return -1;
    }
};