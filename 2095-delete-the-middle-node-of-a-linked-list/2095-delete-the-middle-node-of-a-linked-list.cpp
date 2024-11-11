
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
         int count=0,mid;
       ListNode*temp=head;
       while(1){
        count++;
        if(temp->next==NULL) break;
        temp=temp->next;
       }
       if(count==1) {
        head=head->next;
        return head;
       }
       else if(count%2==0) mid=(count/2)+1;
       else mid=(count+1)/2;
       ListNode*test=head;
       for(int i=1;i<mid-1;i++){
        test=test->next;
       }
       test->next=test->next->next;
       return head;
    }
};