class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode*temp=head;
        int n=0;
        while(1){
            n++;
            if(temp->next==NULL) break;
            temp=temp->next;
        }
        int m=n-k;
        ListNode*test=head;
        temp=head;
        for(int i=0;i<m;i++){
            test=test->next;
        }
        for(int i=1;i<k;i++){
             temp=temp->next;
        }
        int v=temp->val;
        temp->val=test->val;
        test->val=v;
        return head;
    }
};