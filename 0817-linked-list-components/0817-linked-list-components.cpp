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
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_map<int,int>next;
        unordered_map<int,int>prev;
        unordered_map<int,bool>comp;
        comp[-1]=false;

        int pre=-1;
        ListNode*temp=head;

        while(temp!=NULL){
            if(temp->next!=NULL) next[temp->val]=temp->next->val;
            else next[temp->val]=-1;
            prev[temp->val]=pre;
            pre=temp->val;
            comp[temp->val]=false;
            temp=temp->next;
        }
        
        // for(auto &it : prev){
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
        int cmp=0;
        //using -2 for marking

        for(auto &it : nums){
            // cout<<comp[next[it]]<<" "<<comp[prev[it]]<<" "<<next[it]<<" "<<prev[it]<<endl;
            if(comp[next[it]] && comp[prev[it]]){
                cmp--;
                // comp[it]=true;
            }
            else if(comp[next[it]] || comp[prev[it]]){
                // cmp++;
                // cout<<"yes"<<endl;
                // continue;
            }
            else{
                cmp++;
            }
                comp[it]=true;
                // cout<<it<<" "<<comp[it]<<endl;
                // cout<<cmp<<" "<<it<<endl;
        }

        return cmp;
    }
};