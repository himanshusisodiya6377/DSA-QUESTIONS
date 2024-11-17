class Solution {
public:
    int getDecimalValue(ListNode* head) {
    int n=0;
    ListNode*temp=head;
    while(temp!=NULL){
        n++;
        temp=temp->next;
    }      
    temp=head;  
    int POW=pow(2,n-1);
    int sum=0;
    while(temp!=NULL){
        sum+=POW*(temp->val);
        POW/=2;
        temp=temp->next;
    }
    return sum;
    }
};