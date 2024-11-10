class Solution {
public:
    ListNode* middleNode(ListNode* head) {
       int count=0,mid;
       ListNode*temp=head;
       while(1){
        count++;
        if(temp->next==NULL) break;
        temp=temp->next;
       }
       if(count%2==0) mid=(count/2)+1;
       else mid=(count+1)/2;
       ListNode*test=head;
       for(int i=1;i<mid;i++){
        test=test->next;
       }
       head=test;
        return  head;
       

    }
};