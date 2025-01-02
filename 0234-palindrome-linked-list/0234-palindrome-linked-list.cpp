class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode*rest=head;
        ListNode*temp=head;
        if(head==NULL) return head;
        ListNode*test=head->next;
        while(test!=NULL){
           head=test;
           test=test->next;
           head->next=temp;
           temp=head;
        }
        rest->next=NULL;
        return temp;
    }
    bool isPalindrome(ListNode* head) {
    ListNode*slow=head;
    ListNode*fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    // slow->next=NULL;
    ListNode*temp=head;
    ListNode*test=reverseList(slow);
    while(temp!=NULL && test!=NULL){
        if(temp->val != test->val) return false;
        test=test->next;
        temp=temp->next;
    }
    return true;
    }
};