class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
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
};