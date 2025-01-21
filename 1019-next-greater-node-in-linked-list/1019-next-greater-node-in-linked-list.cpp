class Solution {
public:
    ListNode*reversell(ListNode*head){
        ListNode*t=head;
        ListNode*temp=head->next;
        ListNode*test=head->next->next;
        while(head->next!=NULL){
            temp->next=head;
            head=temp;
            temp=test;
            if(test==NULL) break;
            test=test->next;
        }
        t->next=NULL;
        return head;
    }
    int sizeofll(ListNode*head){
        ListNode*temp=head;
        int count=0;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        return count;
    }
    vector<int> nextLargerNodes(ListNode* head) {
      int size=sizeofll(head);
      vector<int>ans(size,0);
      if(size==1) return ans;
      ListNode*tempo=reversell(head);
       ListNode*temp=tempo;
       stack<int>st;
       int i=1;//for indexing
       st.push(temp->val);
       temp=temp->next;
       
        while(temp!=NULL){//presmaller
            while(st.size()>0 && st.top()<=temp->val){
                st.pop();
            }
            if(st.size()!=0){
                ans[i]=st.top();
            }
            st.push(temp->val);
            temp=temp->next;
            i++;
        }
        reverse(ans.begin(),ans.end());
       
        return ans;
    }
};