class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
    if(head==NULL || head->next==NULL) return NULL;
     ListNode*p=head;
     ListNode*s=head;
     ListNode*t=head->next->next;
     s=s->next;
     if(t==NULL || t->next==NULL) return NULL;
     t=t->next->next;
    while(t!=NULL && t->next!=NULL){
            if(s==t) return p->next;
                s=s->next;
                t=t->next->next;
                p=p->next;
        }
        return NULL;
    }
};