class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& arr) {
        int n=arr.size();
         vector<int>v(n,0);
    stack<int>idx;
    //TC:-O(n) SC:-O(n) because of use of stack at worst case there can be all elements in stack
    //push always first and -1 in v as no previous greater
    //than move with for loop and pop all element if its smaller 
    //than store in v[i] and push in stack
    //simple pop v[i] push traverse forward
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