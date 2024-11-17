class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL) return head;
       ListNode*c=new ListNode(-100);
       ListNode*t=c;
       ListNode*temp=head;
       int n=-500;
       while(temp!=NULL && temp->next!=NULL){
        if(temp->val!=temp->next->val){
            if(temp->val!=n){
              t->next=temp;
            temp=temp->next;
            t=t->next;
            }
            else temp=temp->next;
            
        }
        else {
             n=temp->val;
            temp=temp->next;
        }
       }
       if(temp->val==n) temp=temp->next;
       t->next=temp;
       return c->next;
   }
};