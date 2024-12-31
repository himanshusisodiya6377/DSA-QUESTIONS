class Solution {
public:
ListNode*reverseLL(ListNode*head){
    if(head==NULL || head->next==NULL) return head; 
    ListNode*temp=head;
     ListNode*test=head->next->next;
      ListNode*help=head->next;
      while(help!=NULL){
        help->next=temp;
        temp=help;
        help=test;
        if(test==NULL) break;
        else test=test->next;
      }
        head->next=NULL;
        return temp;
}
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      ListNode*fir=reverseLL(l1);
      ListNode*sec=reverseLL(l2);//base new heads
      ListNode*temp=fir;//copy for help
        ListNode*test=sec;
       ListNode*c=new ListNode(-100);
        ListNode*t=c;
        int n=0,m=0;//n for l1 size and m for l2 size
        while(temp!=NULL){
            n++;  //getting size of l1
            temp=temp->next;
        }
          while(test!=NULL){
            m++;  //getting size of l2
            test=test->next;
        }
        temp=fir;
        test=sec;
        int carry=0,z,pu=0;
        if(m==n){ // if size both size eqaul
            while(temp!=NULL && test!=NULL){
                 ListNode*k=new ListNode(-100);
                 t->next=k;
                 t=t->next;
                   z=temp->val+test->val+carry;
                   carry=0;
            if(z<=9){ //if digit sium gretater than 9
                 pu=z;
                 t->val=pu;
               
            }
            else{
                pu=z%10; //value that to be push
                carry=z/10;
                t->val=pu;
            }
            temp=temp->next;
            test=test->next;
            }
               if(carry>0){
                 ListNode*k=new ListNode(-100);
                 t->next=k;
                 t=t->next;
                 t->val=carry;
                 carry=0;
            } 
         }
        else{ // if size is not same
            while(temp!=NULL && test!=NULL){
                 ListNode*k=new ListNode(-100);
                 t->next=k;
                 t=t->next;
                   z=temp->val+test->val+carry;
                   carry=0;
            if(z<=9){ //if digit sium gretater than 9
                 pu=z;
                 t->val=pu;
               
            }
            else{
                pu=z%10; //value that to be push
                carry=z/10;
                t->val=pu;
            }
            temp=temp->next;
            test=test->next;
            } 
            while(test==NULL && temp!=NULL){
                 ListNode*k=new ListNode(-100);
                 t->next=k;
                 t=t->next;
                z=temp->val+carry;
                carry=0;
                if(z<=9){ //if digit sium gretater than 9
                 pu=z;
                 t->val=pu;
            }
            else{
                  pu=z%10; //value that to be push
                carry=z/10;
                t->val=pu;
            }
            temp=temp->next;
            }
            while(temp==NULL && test!=NULL){
                 ListNode*k=new ListNode(-100);
                 t->next=k;
                 t=t->next;
                z=test->val+carry;
                carry=0;
                if(z<=9){ //if digit sium gretater than 9
                 pu=z;
                 t->val=pu;
            }
            else{
                  pu=z%10; //value that to be push
                carry=z/10;
                t->val=pu;
            }
            test=test->next;
            }
            if(carry>0){
                 ListNode*k=new ListNode(-100);
                 t->next=k;
                 t=t->next;
                 t->val=carry;
                 carry=0;
            }
        }
  ListNode*ans=reverseLL(c->next);
  return ans;
    }
};