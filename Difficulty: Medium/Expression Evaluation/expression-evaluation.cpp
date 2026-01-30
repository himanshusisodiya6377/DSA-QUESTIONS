class Solution {
  public:
    int rank(string &s){
        if(s=="^") return 5;
        else if(s=="*" || s=="/") return 4;
        return 3;
    }
    
    void work_diff(stack<int>&val,stack<string>&opr){
        while(!opr.empty() && opr.top()=="^"){
            int fir=val.top(); val.pop();
            int sec=val.top(); val.pop();
            
            int num=pow(sec,fir);
            val.push(num);
            opr.pop();
        }
    }
    
    int work(stack<int>&val,string opr){
        int first=val.top();
        val.pop();
        int second=val.top();
        val.pop();
        
        // cout<<first<<" "<<second<<" "<<opr<<endl;
        
        if(opr=="+") return second+first;
        else if(opr=="-") return second-first;
        else if(opr=="/") return second/first;
        else if(opr=="*") return second*first;
        return pow(second,first);
    }
    int evaluateInfix(vector<string>& arr) {
        // code here
       int n=arr.size();
       stack<string>opr;
       stack<int>val;
       
       for(int i=0;i<n;i++){
           if(arr[i]!="+" && arr[i]!="-" && arr[i]!="*" && arr[i]!="/" && arr[i]!="^"){
               val.push(stoi(arr[i]));
            //   cout<<arr[i]<<endl;
           }
           else{
              if(opr.empty()) {
                  opr.push(arr[i]);
                //   cout<<arr[i]<<endl;
              }
              else if(arr[i]=="^") opr.push(arr[i]);
              else{
                  
                  if(opr.top()=="^"){
                    work_diff(val,opr);    
                  }
                  
                  while(!opr.empty() && rank(opr.top())>=rank(arr[i])){
                      int num=work(val,opr.top());
                    //   cout<<num<<endl;
                    // if(!val.empty() && val.empty()) cout<<val.top()<<endl;
                      opr.pop();
                      val.push(num);
                  }
                  opr.push(arr[i]);
              }
           }
       }
       
       while(!opr.empty()){
           int num=work(val,opr.top());
           opr.pop();
           val.push(num);
       }
       
       return val.top();
    }
};