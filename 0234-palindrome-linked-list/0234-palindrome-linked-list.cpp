class Solution {
public:
    ListNode* reverse(ListNode* head) {
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
    bool isPalindrome(ListNode* head) {
    ListNode*temp=head;
    ListNode*c=reverse(head);    
    ListNode*temp1=c;
    bool flag=false;
    while(temp!=NULL && temp1!=NULL){
        if(temp->val!=temp1->val) flag=true;
        temp=temp->next;
        temp1=temp1->next; 
    }
    if(flag==true) return false;
    else return true;
    }
};