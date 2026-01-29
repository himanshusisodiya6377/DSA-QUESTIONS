class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>ans={INT_MAX,INT_MIN};
        
        // int last_val=0;
        queue<int>q;
        // q.push(0);

        if(head==NULL || head->next==NULL || head->next->next==NULL) return {-1,-1};

        ListNode*prev=head;
        ListNode*curr=head->next;
        ListNode*nxt=head->next->next;
        int i=2;
        while(nxt!=NULL){
            if(curr->val>prev->val && curr->val>nxt->val || curr->val<prev->val && curr->val<nxt->val){
                if(!q.empty()){
                ans[0]=min(ans[0],i-q.back());
                ans[1]=max(ans[1],i-q.front());
                }
                // last_val=curr->val;
                cout<<i<<endl;
                q.push(i);
            }
            i++;
            prev=curr;
            curr=nxt;
            nxt=nxt->next;
        }
        
        if(ans[0]==INT_MAX) return {-1,-1};
        return  ans;

    }
};