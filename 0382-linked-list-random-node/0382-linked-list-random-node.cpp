class Solution {
public:
vector<int>arr;
    Solution(ListNode* head) {
        ListNode*temp=head;
        while(temp){
            arr.push_back(temp->val);
            temp=temp->next;
        }
    }
    
    int getRandom() {
        int n=arr.size();
        int idx=rand()%n;
        return arr[idx];
    }
};

