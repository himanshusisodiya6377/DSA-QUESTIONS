class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        //optimise it in peak element
        int n=0;
        vector<int>ans;
        vector<int>v;
        vector<int>idx;
        ListNode*temp=head;
        while(temp!=NULL){
            temp=temp->next;
            n++;
        }
        temp=head;
        if(n==1 || n==0 || n==2){
            for(int i=1;i<=2;i++) ans.push_back(-1); 
            return ans;
        }
        // while(temp!=NULL){
        //      v.push_back(temp->val);
        //     temp=temp->next;
           
        // }
        ListNode*main=head->next;
        ListNode*Next=main->next;
        int i=1;
         while(Next!=NULL){
            if((main->val<temp->val) && (main->val<Next->val)) idx.push_back(i);
            if((main->val>temp->val) && (main->val>Next->val)) idx.push_back(i);
            i++;
            temp=temp->next;
            main=main->next;
            Next=Next->next;
          }
         int min=INT_MAX;
         int max=INT_MIN;
         if(idx.size()==0 || idx.size()==1){
             for(int i=1;i<=2;i++) ans.push_back(-1); 
            return ans;
         }
        //  for(int i=0;i<idx.size()-1;i++){
        //     for(int j=i+1;j<idx.size();j++){
        //        int m=idx[j]-idx[i];
        //        if(m>max) max=m;
        //        if(m<min) min=m;
        //     }
        //  }
         int k=idx.size();
         max=idx[k-1]-idx[0];
         for(int i=0;i<k-1;i++){
            int m=idx[i+1]-idx[i];
            if(m<min) min=m;
 
         }
         
         ans.push_back(min);
         ans.push_back(max);
         return ans;
    }
};