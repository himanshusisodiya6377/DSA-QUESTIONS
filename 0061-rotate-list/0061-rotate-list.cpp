class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL) return head;
        int n=0;
    ListNode*temp=head;
    ListNode*tail=head->next;
    while(1){
        n++;
        if(temp->next==NULL) break;
        temp=temp->next;
    }
    temp=head;
    // while(1){
    //   if(k>13){
    //         k/=n;
    //     }
    //     else break;
    // }
    if(k>9) k=k%n;
    while(k>0){
          while(tail->next!=NULL){
        temp=temp->next;
        tail=tail->next;
              }    
    tail->next=head;
    temp->next=NULL;
     head=tail;
     tail=head->next;
     temp=head;
    k--;
    }
   
    return head;
}
};