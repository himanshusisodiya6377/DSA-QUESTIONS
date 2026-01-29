class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode*c=new ListNode(-100);
        ListNode*p=c;
        int sum=0;
        ListNode*temp=head->next;
        while(temp!=NULL){
            while(temp->val!=0){
                sum+=temp->val;
                temp=temp->next;
            }
            temp=temp->next;
            ListNode*t=new ListNode(sum);
            sum=0;
            c->next=t;
            c=t;
        }
        return p->next;
    }
};