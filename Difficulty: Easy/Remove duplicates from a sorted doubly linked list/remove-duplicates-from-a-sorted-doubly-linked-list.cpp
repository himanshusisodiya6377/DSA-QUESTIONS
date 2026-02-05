/*
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }

};
*/

class Solution {
  public:

    Node *removeDuplicates(struct Node *head) {
        // Your code here
        Node*temp=head;
        while(temp!=NULL && temp->next!=NULL){
            if(temp->next->data==temp->data && temp->next->next!=NULL){
                temp->next->next->prev=temp;
                temp->next=temp->next->next;
            }
            else if(temp->next->data==temp->data){
                temp->next->prev=NULL;
                temp->next=NULL;
            }
            else temp=temp->next;
        }
        return head;
    }
};