/*
class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
        // code here
        Node*temp=head->next;
        Node*curr=head;
        while(1){
            curr->next=curr->prev;
            curr->prev=temp;
            if(temp==NULL) break;
            curr=temp;
            temp=temp->next;
        }
        
        return curr;
    }
};