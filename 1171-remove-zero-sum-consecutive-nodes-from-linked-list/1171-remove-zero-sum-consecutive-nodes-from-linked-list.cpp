class Solution {
public:
    void mark(vector<int>&v,int i,int j){
        for(int k=i;k<=j;k++){
            v[k]=0;
        }
    }
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode*temp=head;
        int n=0;
        while(temp){
            n++;
          temp=temp->next;
        }
        temp=head;
       vector<int>v(n,0);
       int i=0;
       while(temp){
        v[i]=temp->val;
        i++;
        temp=temp->next;
       }
       for(int j=0;j<n;j++){
        int sum=0;
        for(int k=j;k<n;k++){
          sum+=v[k];
          if(sum==0){
            mark(v,j,k);
            break;
          }
        }
       }
       ListNode*c=new ListNode(-100);
       ListNode*check=c;
       for(int k=0;k<n;k++){
        if(v[k]!=0){
          ListNode*test=new ListNode(v[k]);
          check->next=test;
          check=check->next;
        }
       }
       return c->next;
    }
};