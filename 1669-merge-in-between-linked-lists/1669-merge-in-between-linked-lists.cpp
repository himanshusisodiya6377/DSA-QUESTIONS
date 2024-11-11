class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
     ListNode*temp1=list1;
     ListNode*temp2=list2;
      while(temp2->next!=NULL){
        temp2=temp2->next;
    }

    for(int i=0;i<b;i++){
        temp1=temp1->next;
     }  
     temp2->next=temp1->next;
     temp1=list1;
     for(int i=1;i<a;i++){
        temp1=temp1->next;
     } 
     temp1->next=list2;
     return list1;
    }
   
};