class Solution {
public:
void revpart(vector<int>&v,int i,int j){
     reverse(v.begin()+i,v.begin()+j);
}  
ListNode* reverseKGroup(ListNode* head, int k) {
        vector<int>v;
        ListNode*temp=head;
    while(temp!=NULL){
        v.push_back(temp->val);
        temp=temp->next;
     }
    //  int size=0;
    //  temp=head;
    //  while(temp!=NULL){
    //     size++;
    //     temp=temp->next;
    //  }
     for(int i=0;i<v.size();i+=k){
        if((i+k)<=v.size()) revpart(v,i,i+k);
     }
     ListNode*c=new ListNode(-100);
     ListNode*t=c;
     for(int i=0;i<v.size();i++){
        ListNode*test=new ListNode(v[i]);
        t->next=test;
        t=t->next;
     }
     return c->next;

    }
};