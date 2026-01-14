class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
        // Code here
        int cnt=0;
        deque<int>p;
        deque<int>t;
        
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]=='P'){
                while(!t.empty() && t.front()+k<i) t.pop_front();
                
                if(!t.empty()){
                t.pop_front();
                cnt++;
                }
                else p.push_back(i);
            }
            else{
                while(!p.empty() && p.front()+k<i) p.pop_front();
                
                if(!p.empty()){
                p.pop_front();
                cnt++;
                }
                else t.push_back(i);
            }
        }
        
        return cnt;
    }
};