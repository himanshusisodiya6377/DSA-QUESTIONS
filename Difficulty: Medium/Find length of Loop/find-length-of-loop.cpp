/*
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    int lengthOfLoop(Node *head) {
        
        if(head==NULL) return 0;
        if(head->next==NULL) return 0;
        // code here
        Node*slow=head;
        Node*fast=head;
        bool flag=false;
        while(fast!=NULL && fast->next!=NULL){
           
            slow=slow->next;
            fast=fast->next->next;
             if(slow==fast){
                flag=true;
                break;
            }
        }
        
        if(!flag) return 0;
        
        int cnt=1;
        
        if(flag){
        Node*temp=slow->next;
        while(temp!=slow){
            temp=temp->next;
            cnt++;
        }
        }
        return cnt;
    }
};