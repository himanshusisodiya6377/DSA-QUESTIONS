class Solution {
public:
    ListNode* swapPairs(ListNode* head) {

        if(head==NULL) return NULL;
        if(head->next==NULL) return head;

        ListNode*preprev=NULL;
        ListNode*prev=head;
        ListNode*temp=head->next;
        ListNode*c=temp;

        while(temp!=NULL){
            prev->next=temp->next;
            temp->next=prev;
            if(preprev!=NULL){
                preprev->next=temp;
            }
            if(temp->next==NULL || temp->next->next==NULL || temp->next->next->next==NULL) break;
            temp=temp->next->next->next;
            preprev=prev;
            if(temp==NULL) break;
            prev=prev->next;

        }

        return c;
    }
};