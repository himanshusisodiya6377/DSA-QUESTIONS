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
    typedef pair<int,ListNode*> z;
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();

        if(n==0) return NULL;
        
        ListNode*c=new ListNode(0);
        ListNode*head=c;
        
        priority_queue<z,vector<z>,greater<z>>pq; //val idx
        
        for(int j=0;j<n;j++){
            if(lists[j]!=NULL) pq.push({lists[j]->val,lists[j]});
        }

        // cout<<pq.size()<<endl;
        
        while(!pq.empty()){
            auto p=pq.top();
            pq.pop();
            
            int val=p.first;
            ListNode*temp=p.second;
            
            c->next=temp;
            c=temp;
            // cout<<"yes";
            if(temp->next) pq.push({temp->next->val,temp->next});
        }
        return head->next;
    }
};