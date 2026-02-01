class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head->next==NULL || head==NULL) return head;
        ListNode*curr=head;
        ListNode*prev=NULL;
        ListNode*nxt=head->next;
        ListNode*conn=NULL;
        int temp=left;

        while(left>1){
            conn=curr;
            prev=curr;
            curr=nxt;
            nxt=nxt->next;
            left--;
        }

        ListNode*lf=curr;
        int diff=right-temp;
        while(diff>=0){
            
            curr->next=prev;
            prev=curr;
            curr=nxt;
            if(nxt!=NULL) nxt=nxt->next;
            diff--;

        }

        //now connct
        lf->next=curr;
        if(conn!=NULL) conn->next=prev;

        return (temp==1 ? prev :head);
    }
};