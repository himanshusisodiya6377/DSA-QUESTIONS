class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        vector<int>v;
        ListNode*temp=head;
        while(temp!=NULL){
            v.push_back(temp->val);
            temp=temp->next;
        }
        stack<int>st;
        int n=v.size();
        vector<int>ans(n,0);
        st.push(v[n-1]);
        for(int i=n-2;i>=0;i--){
            while(st.size()>0 && st.top()<=v[i]) st.pop();
            if(st.size()!=0) ans[i]=st.top();
            st.push(v[i]);
        }
        ListNode*head1=new ListNode(-100);
        temp=head1;
        for(int i=0;i<ans.size();i++){
            if(ans[i]==0){
                ListNode*tempo=new ListNode(v[i]);
                temp->next=tempo;
                temp=tempo;
            }
        }
        return head1->next;
    }
};