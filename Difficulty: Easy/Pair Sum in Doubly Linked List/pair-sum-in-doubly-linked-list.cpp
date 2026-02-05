// User function Template for C++

/* Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
*/

class Solution {
  public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
      Node*temp=head;
      Node*tail=head;
      while(tail->next) tail=tail->next;
      vector<pair<int,int>>ans;
      while(temp!=tail){
        int sum=temp->data + tail->data;
        if(sum==target){
            ans.push_back({temp->data,tail->data});
            temp=temp->next;
        }   
        else if(sum<target) temp=temp->next;
        else tail=tail->prev;
      }
    return ans;
    }
};