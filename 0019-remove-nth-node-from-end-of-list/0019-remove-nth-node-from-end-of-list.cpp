class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      int count=0;
      ListNode*temp=head;
      while(1){
        count++;
        if(temp->next==NULL) break;
        temp=temp->next;
      }
      int ans=count-n;
      if(ans==0){
        head=head->next;
        return head;
      }
      else if(ans==count){
        ListNode*tail=head;
        while(tail->next->next!=NULL){
            tail=tail->next;
        }
        tail=tail->next->next;
        return head;
        
      }
      else{
          temp=head;
      for(int i=1;i<ans;i++){
          temp=temp->next;
      }
      temp->next=temp->next->next;
      return head;
      }
    }
};