class Solution {
public:
      ListNode* merge(ListNode* list1, ListNode* list2) {
   ListNode*c=new ListNode(-100);
   ListNode*temp=c;
   ListNode*temp1=list1;
   ListNode*temp2=list2;
   while(temp1!=NULL && temp2!=NULL){
    if(temp1->val < temp2->val){
        temp->next=temp1;
        temp1=temp1->next;
        temp=temp->next;
    }
    else{
        temp->next=temp2;
        temp2=temp2->next;
        temp=temp->next;
    }
   
   }
   if(temp1==NULL) temp->next=temp2;
   else temp->next=temp1;
 return c->next;
    }
    ListNode* sortList(ListNode* head){
        if(head==NULL || head->next==NULL) return head;
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
      
        ListNode*a=head;
        ListNode*b=slow->next;
          slow->next=NULL;
        a=sortList(a);
        b=sortList(b);
        return merge(a,b);
    } 
};