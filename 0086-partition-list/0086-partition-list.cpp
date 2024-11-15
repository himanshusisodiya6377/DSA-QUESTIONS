class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode*c1= new ListNode(-100);
        ListNode*c2= new ListNode(-100);
        ListNode*temp=head;
        ListNode*less=c1;
        ListNode*more=c2;
        while(temp!=NULL){
            if(temp->val<x){
                less->next=temp;
                temp=temp->next;
                less=less->next;
            }
            else{
                 more->next=temp;
                temp=temp->next;
                more=more->next;
            }
        }
        less->next=NULL;
        more->next=NULL;
        less->next=c2->next;
        return c1->next;
    }
};