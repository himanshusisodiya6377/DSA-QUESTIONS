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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        int n=nums.size();
        unordered_set<int>st;
        for(auto it : nums) st.insert(it);
        bool flag=true;
        ListNode*c=new ListNode(-1);
        c->next=head;
        ListNode*temp=head;
        while(head!=NULL){
            if(st.find(head->val)!=st.end()){
                if(flag){
                    head=head->next;
                    temp=head;
                    c->next=head;
                }
                else{
                    temp->next=head->next;
                    head=temp->next;
                }
            }
            else{
                if(flag) flag=false;
                else {
                    temp=temp->next;
                }
                head=head->next;

            }
        }
        return c->next;
    }
};