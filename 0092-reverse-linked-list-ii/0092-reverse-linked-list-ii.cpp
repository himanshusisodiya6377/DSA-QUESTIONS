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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        vector<int>v;
        ListNode*temp=head;
        while(temp!=NULL){
            v.push_back(temp->val);
            temp=temp->next;
        }
        reverse(v.begin()+left-1,v.begin()+right);

        ListNode*c=new ListNode(-1);
        temp=c;
        for(int i=0;i<v.size();i++){
            ListNode*d=new ListNode(v[i]);
            if(c==NULL){
                c->next=d;
                temp=d;
            }
            else{
                temp->next=d;
                temp=d;
            }
        }
        return c->next;
    }
};