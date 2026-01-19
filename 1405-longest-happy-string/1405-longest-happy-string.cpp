class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        
        priority_queue<pair<int,char>>pq;

        pq.push({a,'a'});
        pq.push({b,'b'});
        pq.push({c,'c'});

        string ans="";

        
       int maxi1=pq.top().first;
       cout<<maxi1<<endl;
       char cmaxi1=pq.top().second;
       
       pq.pop();

       int maxi2=pq.top().first;
       cout<<maxi2<<endl;
       char cmaxi2=pq.top().second;
       pq.pop();

      while(maxi2>0){
         if(maxi1>1){
            ans.push_back(cmaxi1);
            ans.push_back(cmaxi1);
            maxi1-=2;
         }
         else if(maxi1==1){
            ans.push_back(cmaxi1);
            maxi1--;
         }

         if(maxi2>1){
            ans.push_back(cmaxi2);
            ans.push_back(cmaxi2);
            maxi2-=2;
         }
         else if(maxi2==1){
            ans.push_back(cmaxi2);
            maxi2--;
         }
      }

      maxi2=pq.top().first;
       cout<<maxi1<<" "<<maxi2<<endl;
      cmaxi2=pq.top().second;

      if(maxi1<maxi2){
        cout<<"yes"<<endl;
        swap(maxi1,maxi2);
        swap(cmaxi1,cmaxi2);
      }

       while(maxi2>0){
         if(maxi1>1){
            ans.push_back(cmaxi1);
            ans.push_back(cmaxi1);
            maxi1-=2;
         }
         else if(maxi1==1){
            ans.push_back(cmaxi1);
            maxi1--;
         }

         if(maxi2>1){
            ans.push_back(cmaxi2);
            ans.push_back(cmaxi2);
            maxi2-=2;
         }
         else if(maxi2==1){
            ans.push_back(cmaxi2);
            maxi2--;
         }
      }

    //   cout<<maxi1<<endl;

    //   if(maxi1>2) return "";

      if(maxi1>=2){
          ans.push_back(cmaxi1);
          ans.push_back(cmaxi1);
      }
      else if(maxi1==1)  ans.push_back(cmaxi1);

      return ans;
    }
};