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

class Solution {
  public:
    
   void merge(Node*arr1,Node*arr2){
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
       
    //   return c->next;
   }
    Node* mergeKLists(vector<Node*>& arr) {
        // code here
        Node*c=new Node(-1);
        int n=arr.size();
        for(int i=0;i<n;i++){
            merge(c,arr[i]);
        }
        
        return c->next;
    }
};