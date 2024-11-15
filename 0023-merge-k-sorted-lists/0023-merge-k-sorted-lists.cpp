class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int row=lists.size();
        if(row==0) return NULL;
        int i=1;
        ListNode*c=new ListNode(-100);
        ListNode*temp=c;
        ListNode*temp1=lists[lists.size()-1];
        lists.pop_back();
         temp->next=temp1;
    while(i<row){
            ListNode*temp2=lists[lists.size()-1];
            i++;
    while(temp1!=NULL && temp2!=NULL){
        if(temp1->val <= temp2->val){
        temp1=temp1->next;
        temp=temp->next;
           }
          else{
        temp->next=temp2;
        temp2=temp2->next;
        temp=temp->next;
        temp->next=temp1;
    }
         if(temp1==NULL) temp->next=temp2;
   else temp->next=temp1;

            }
         
    lists.pop_back();
    temp=c;
    temp1=temp->next;
   
       }
     return c->next;
    }
};