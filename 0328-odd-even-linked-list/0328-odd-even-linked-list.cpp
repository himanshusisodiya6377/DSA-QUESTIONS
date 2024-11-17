class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
         ListNode*c1= new ListNode(-100);
        ListNode*c2= new ListNode(-100);
        ListNode*temp=head;
        ListNode*odd=c1;
        ListNode*even=c2;
        int n=1;
        while(temp!=NULL){
            if((n)%2!=0){
                odd->next=temp;
                temp=temp->next;
                odd=odd->next;
                n++;
            }
            else{
                 even->next=temp;
                temp=temp->next;
                even=even->next;
                n++;
            }
        }
        odd->next=NULL;
        even->next=NULL;
        odd->next=c2->next;
        return c1->next;
    }
};