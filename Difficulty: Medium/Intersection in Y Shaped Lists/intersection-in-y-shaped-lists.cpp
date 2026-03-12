/*
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* intersectPoint(Node* head1, Node* head2) {
        //  Code Here
        int lng1=0,lng2=0;
        
        Node*temp=head1;
        Node*t=head2;
        
        while(temp!=NULL){
            temp=temp->next;
            lng1++;
        }
        
        while(t!=NULL){
            t=t->next;
            lng2++;
        }
        
        temp=head1,t=head2;
        
        int diff=abs(lng1-lng2);
        
        if(lng1>lng2){
            while(diff>0){
                diff--;
                temp=temp->next;
            }
        }
        if(lng2>lng1){
            while(diff>0){
                diff--;
                t=t->next;
            }
        }
        
        while(t!=temp){
            t=t->next;
            temp=temp->next;
        }
        
        return t;
    }
};