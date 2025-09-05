/* Node is defined as
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
        vector<int>v;
        Node*temp=head;
        while(temp!=NULL){
            v.push_back(temp->data);
            temp=temp->next;
        }
        
        sort(v.begin(),v.end());
        
        Node*c=new Node(-1);
        
        for(int i=0;i<v.size();i++){
            Node*d=new Node(v[i]);
            if(c->next==NULL){
                c->next=d;
                temp=d;
            }
            else{
                temp->next=d;
                temp=d;
            }
        }
        
        return c->next;
    }
};