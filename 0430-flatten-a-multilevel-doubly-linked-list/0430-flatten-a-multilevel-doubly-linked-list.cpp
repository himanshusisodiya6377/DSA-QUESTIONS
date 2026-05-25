/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(head==NULL) return head;

        Node*temp=head;
        while(temp!=NULL){

            //have child
            if(temp->child!=NULL){
                // Node*dummy=temp;
                Node*ahead=temp->next;
                Node*dummy=flatten(temp->child);
                temp->next=dummy;
                dummy->prev=temp;
                Node*tail=dummy;
                while(tail->next!=NULL) tail=tail->next;
                tail->next=ahead;
                if(ahead!=NULL) ahead->prev=tail;
                temp->child=NULL;
                // delete dummy;
            }
            
                temp=temp->next;
            
        }
        return head;
    }
};