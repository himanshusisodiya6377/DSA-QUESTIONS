/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    int countNode(Node*root){
        Node*curr=root;
        int nodes=0;
        while(curr!=NULL){
            if(curr->left==NULL){
                nodes++;
                curr=curr->right;
            }
            else{
                Node*temp=curr->left;
                while(temp->right!=NULL && temp->right!=curr) temp=temp->right;
                if(temp->right==NULL){
                    temp->right=curr;
                    curr=curr->left;
                }
                else {
                    temp->right=NULL;
                    nodes++;
                    curr=curr->right;
                }
            }
        }
        return nodes;
    }
    int findMedian(Node* root) {
        // Code here
        int n=countNode(root);
         int medianIndex;


    if (n % 2 == 0) medianIndex = n / 2;
    else medianIndex = (n + 1) / 2;

    Node* curr = root;
    int nodes = 0;
    while (curr != nullptr) {
        if (curr->left == nullptr) {
            nodes++;
            if (nodes == medianIndex) return curr->data;
            curr = curr->right;
        } else {
            
        
            Node* prev = curr->left;
            while (prev->right != nullptr && prev->right != curr) {
                prev = prev->right;
            }
            
          
            if (prev->right == nullptr) {
                prev->right = curr;
                curr = curr->left;
            } else {
                nodes++;
                if (nodes == medianIndex) return curr->data;
                
  
                prev->right = nullptr;
                curr = curr->right;
            }
        }
    }
    return -1;
    }
};