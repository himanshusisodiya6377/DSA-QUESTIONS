class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        int sz=0;
        ListNode*temp=head;
        while(temp!=NULL){
            sz++;
            temp=temp->next;
        }
        vector<int>ans(sz,0);

        stack<pair<int,int>>st;

        temp=head;
        int idx=0;
        while(temp!=NULL){
            // if(st.empty()) st.push({temp->val,idx});
            
            while(!st.empty()){
               if(st.top().first<temp->val){
                ans[st.top().second]=temp->val;
                st.pop();
               }
               else break;
            }

            st.push({temp->val,idx});
            temp=temp->next;


            idx++;
        }

        return ans;
    }
};