class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*temp=l1;
        ListNode*temp1=l2;
        vector<int>v1;
        vector<int>v2;
        vector<int>ans;
        while(temp!=NULL){
            v1.push_back(temp->val);
            temp=temp->next;
        }
        while(temp1!=NULL){
            v2.push_back(temp1->val);
            temp1=temp1->next;
        }
        int n=min(v1.size(),v2.size());
        int z=0;
        int m=0;
        while(n>0){
            if((v1[0] + v2[0]+z)>9){
                 z=(v1[0] + v2[0]+z);
                m=z%10;
                ans.push_back(m);
                z=z/10;
               
                v1.erase(v1.begin());
                v2.erase(v2.begin());                // m=(v1[v1.size()-1] + v2[v2.size()-1])-k;
                // ans.push_back(m);
                m=0;
            }
            else{
                m=(v1[0] + v2[0])+z;
                ans.push_back(m);
               v1.erase(v1.begin());
                v2.erase(v2.begin());   
                m=0;
                z=0;
            }
            n--;
        }
        // if(z>0) ans.push_back(z);
        if(v2.size()==0 && v1.size()>0){ 
         while(v1.size()>0){
             int p=v1[0]+z;
              if(p>9){
            m=p%10;
            ans.push_back(m);
            z=p/10;
            m=0;
         }
         else {
            ans.push_back(p);
            z=0;
         }
         v1.erase(v1.begin());
         }
        }
        else if(v1.size()==0 && v2.size()>0){
        while(v2.size()>0){
             int p=v2[0]+z;
              if(p>9){
            m=p%10;
            ans.push_back(m);
            z=p/10;
            m=0;
         }
          else {
            ans.push_back(p);
            z=0;
         }
         v2.erase(v2.begin());
         }
         }
        
        if(z>0) ans.push_back(z);
         ListNode*N=new ListNode(-100);
         ListNode*res=N;
         int s=0;
        while(s<ans.size()){
            ListNode*New=new ListNode(ans[s]);
            N->next=New;
            N=N->next;
            s++;
        }
        return res->next;
    }
};