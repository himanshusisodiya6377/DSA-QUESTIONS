/*
class Node {
public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

 Node* merge(Node*arr1,Node*arr2){
       Node*temp1=arr1;
       Node*temp2=arr2;
       Node*c=new Node(-1);
       Node*temp=c;
       while(temp1!=NULL && temp2!=NULL){
           if(temp1->data<=temp2->data){
               temp->next=temp1;
               temp1=temp1->next;
               temp=temp->next;
           }
           else{
               temp->next=temp2;
               temp2=temp2->next;
               temp=temp->next;
           }
       }
       
       while(temp1!=NULL){
           temp->next=temp1;
           temp1=temp1->next;
           temp=temp->next;
       }
       
       while(temp2!=NULL){
           temp->next=temp2;
           temp2=temp2->next;
           temp=temp->next;
       }
    //   
    //   arr1=c->next;/
      return c->next;
   }
   
class Solution {
  public:
    Node* mergeSort(Node* head) {
        // code here
    if(!head || !head->next) return head;
       Node*slow=head;
       Node*fast=head->next;
       while(fast!=NULL && fast->next!=NULL){
           slow=slow->next;
           fast=fast->next->next;
       }
       Node*temp=slow->next;
       slow->next=NULL;
       
       Node*right=mergeSort(head);
       
       
       Node*left=mergeSort(temp);
       
     return merge(left,right);
      
    }
};