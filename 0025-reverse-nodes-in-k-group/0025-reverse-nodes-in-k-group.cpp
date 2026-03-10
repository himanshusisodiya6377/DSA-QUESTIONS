/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL) return head;
        ListNode*temp=head;
        int cnt=0;

        while(temp!=NULL){
            temp=temp->next;
            cnt++;
        }

        if(cnt<k) return head;

        ListNode*prev=NULL;
        ListNode*curr=head;
        ListNode*nxt=NULL;
        cnt=0;

        while(curr!=NULL && cnt<k){
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
            cnt++;
        }

        if(nxt!=NULL) head->next=reverseKGroup(nxt,k);

        return prev;
    }
};