class Solution {
  public:
    
    Node* mergeTwoLL(Node*head1,Node*head2){
        
        Node*d=new Node(0); //temporary created
        Node*temp=d;
        
        while(head1!=NULL && head2!=NULL){
            if(head1->data<head2->data){
                temp->bottom=head1;
                head1=head1->bottom;
             
                temp=temp->bottom;   
            }
            else{
                temp->bottom=head2;
                head2=head2->bottom;
             
                temp=temp->bottom;   
            }
        }
        
       temp->bottom=(head1!=NULL ? head1 : head2);
        
        // temp->bottom=NULL;
        return d->bottom;
    }
    Node *flatten(Node *root) {
        
        if(root==NULL) return NULL;
        // code here
        Node*head2=flatten(root->next);
        
        return mergeTwoLL(root,head2);
    }
};