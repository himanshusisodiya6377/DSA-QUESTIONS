class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        vector<int>v;
        ListNode*temp=head;
        while(temp!=NULL){
            v.push_back(temp->val);
            temp=temp->next;
        }
       //reverse(v.begin(), v.end());
       ListNode*c=new ListNode(-100);
       ListNode*a=c;
       while(v.size()>0){
          ListNode*test=new ListNode(v[v.size()-1]);
             a->next=test;
             a=a->next;
             v.pop_back();
       }
       return c->next;
    }
};