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
    Node* swapKth(Node* head, int k) {
        // code here
        if(!head) return head;
        
        int n=0;
        Node*temp=head;
        while(temp!=NULL){
            n++;
            temp=temp->next;
        }
        
        if(k>n) return head;
        if(n==1) return head;
        if(2*k-1==n) return head;
        
        Node*x_prev=NULL;
        Node*x=head;
        
        for(int i=1;i<k;i++){
            x_prev=x;
            x=x->next;
        }
        
        Node*y_prev=NULL;
        Node*y=head;
        
        for(int i=1;i<n-k+1;i++){
            y_prev=y;
            y=y->next;
        }
        
        if(x_prev) x_prev->next=y;
        if(y_prev) y_prev->next=x;
        
        temp=x->next;
        
        x->next=y->next;
        y->next=temp;
        
        if(k==1) head=y;
        if(k==n) head=x;
        
        return head;
    }
};