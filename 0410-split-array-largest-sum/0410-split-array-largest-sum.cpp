class Solution {
public:
int get(vector<int>arr,int mid){
   int count=1;
   int temp=0;
   for(int i=0;i<arr.size();i++){
        temp+=arr[i];
        if(temp>mid){
          count++;
          temp=arr[i];
        }
   }
     return count;
}
int splitArray(vector<int>& arr, int k) {
  int n=arr.size();
  int max=INT_MIN;
  int sum=0;
  for(int i=0;i<n;i++){
    sum+=arr[i];
    if(max<arr[i]) max=arr[i];
  }
  int lo=max,hi=sum;
  while(lo<=hi){
      int mid=(lo+hi)/2;
      int x=get(arr,mid);
      if(x<=k) hi=mid-1;
      else lo=mid+1;
  }
  return lo;
    }
};