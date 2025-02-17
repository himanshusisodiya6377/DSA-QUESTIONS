class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int k=flowerbed.size();
        if(k==1){
            if(flowerbed[0]==0) n--;
        }
        else{
           if(flowerbed[0]==0 && flowerbed[1]==0){
              n--;
              flowerbed[0]=1;
           } 
         if(flowerbed[k-1]==0 && flowerbed[k-2]==0) {
            n--;
            flowerbed[k-1]=1;
         }
        for(int i=1;i<k-1;i++){
            if(flowerbed[i]!=1){
                if(flowerbed[i-1]!=1 && flowerbed[i+1]!=1) {
                    n--;
                     flowerbed[i]=1;
                }
            }
        }
        }
        
        if(n<=0) return true;
        else return false;
    }
};