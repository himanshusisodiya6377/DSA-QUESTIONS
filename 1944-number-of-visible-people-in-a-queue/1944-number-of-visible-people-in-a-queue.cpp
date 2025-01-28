class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& arr) {
        int n=arr.size();
         vector<int>v(n,0);
    stack<int>idx;
    //TC:-O(n) SC:-O(n) because of use of stack at worst case there can be all elements in stack
    //calculate the number of pop as it is equal to the persons he can watch
    //if size not zero means num+1 else num  easy question
    idx.push(n-1);
    for(int i=n-2;i>=0;i--){
        int num=0;
      while(idx.size()>0 && arr[idx.top()]<=arr[i]) {
        idx.pop();
        num++;
      }
      if(idx.size()!=0) v[i]=num+1;
      else v[i]=num;
      idx.push(i);
    }
    return v;
    }
};