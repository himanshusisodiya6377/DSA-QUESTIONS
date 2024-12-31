class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
       ListNode*temp=headA;
       ListNode*test=headB;
       ListNode*c=new ListNode(-100);
       ListNode*t=c;
       int n=0;
       while(temp!=NULL){
        n++;
        temp=temp->next;
       }
       int m=0;
       while(test!=NULL){
        m++;
        test=test->next;
       }
       int diff=abs(m-n);
       temp=headA;
       test=headB;
       if(n>m){
        while(diff>0){
            temp=temp->next;
            diff--;
        }
        test=headB;
       }
       else{
        while(diff>0){
            test=test->next;
            diff--;
        }
       }
       while(temp!=NULL && test!=NULL){
        if(temp==test){
            t->val=temp->val;
            return c;
            break;
        }
        test=test->next;
        temp=temp->next;
       }    
       return c->next; 
    }
};