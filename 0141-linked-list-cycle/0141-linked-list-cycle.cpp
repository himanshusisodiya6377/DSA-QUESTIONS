class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        if(head==NULL || head->next==NULL) return false;
        ListNode*s=head; 
        ListNode*t=head->next->next;
        while(t->next!=NULL && t!=NULL){
            if(s==t) return true;
            else{
                s=s->next;
                t=t->next->next;
            }
        }
        return false;
    }
};