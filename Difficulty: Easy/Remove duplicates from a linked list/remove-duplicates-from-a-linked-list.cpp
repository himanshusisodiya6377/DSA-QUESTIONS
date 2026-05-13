/*
The structure of linked list is the following

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution {
  public:
    Node *removeDuplicates(Node *head) {
        // your code goes here
        Node*prev=NULL;
        Node*temp=head;
        unordered_set<int>st;
        while(temp!=NULL){
            if(st.count(temp->data)){
                prev->next=temp->next;
                temp=temp->next;
            }
            else{
            prev=temp;
            temp=temp->next;
            }
            st.insert(prev->data);
        }
        return head;
    }
};