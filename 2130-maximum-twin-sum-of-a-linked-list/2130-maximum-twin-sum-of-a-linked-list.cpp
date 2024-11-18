class Solution {
public:
    int pairSum(ListNode* head) {
        int n=0;
        ListNode*temp=head;
        vector<int>c;
        int max=INT_MIN;
        while(temp!=NULL){
            n++;
            c.push_back(temp->val);
            temp=temp->next;
        }
        temp=head;
        int i=0,j=n-1;
        while(i<j){
            int sum=c[i]+c[j];
            if(sum>max) max=sum;
            i++;
            j--;
        }
        
        // ListNode*twin=head;
        // while(temp!=NULL){
        //     n++;
        //     temp=temp->next;
        // }
        // temp=head;
        // int max=INT_MIN;
        // for(int i=0;i<n/2;i++){
        //     int t=n-i;
        //     while(t>1){
        //         twin=twin->next;
        //         t--;
        //     }
        //     int add=(twin->val)+(temp->val);
        //     if(add>max) max=add;
        //     temp=temp->next;
        //     twin=head;
        // }
        return max;
    }
};