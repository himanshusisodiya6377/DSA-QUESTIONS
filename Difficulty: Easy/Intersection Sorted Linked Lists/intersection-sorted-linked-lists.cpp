//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        cout << temp->data << ' ';
        temp = temp->next;
    }
    cout << '\n';
}


// } Driver Code Ends
class Solution {
  public:
    Node* findIntersection(Node* head1, Node* head2) {
        Node*c=new Node(-100);
        Node*t=c;
        int n=0,m=0;
        Node*temp=head1;
        while(temp!=NULL){
            n++;
            temp=temp->next;
        }
        temp=head2;
        while(temp!=NULL){
            m++;
            temp=temp->next;
        }
        Node*test=head1;
        for(int i=0;i<n;i++){
            temp=head2;
            for(int j=0;j<m;j++){
                if(test->data==temp->data){
                    t->next=test;
                    t=t->next;
                }
                temp=temp->next;
            }
            test=test->next;
        }
        t->next=NULL;
        return c->next;
    }
};


//{ Driver Code Starts.

// Driver program to test above functions
int main() {
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n1, n2, tmp;
        Node *head1 = nullptr, *tail1 = nullptr;
        Node *head2 = nullptr, *tail2 = nullptr;
        string input1, input2;

        getline(cin, input1); // Read the entire line for LL1 elements
        stringstream ss1(input1);
        while (ss1 >> tmp) {
            Node *new_node = new Node(tmp);
            if (head1 == nullptr) {
                head1 = new_node;
                tail1 = new_node;
            } else {
                tail1->next = new_node;
                tail1 = new_node;
            }
        }

        getline(cin, input2); // Read the entire line for LL2 elements
        stringstream ss2(input2);
        while (ss2 >> tmp) {
            Node *new_node = new Node(tmp);
            if (head2 == nullptr) {
                head2 = new_node;
                tail2 = new_node;
            } else {
                tail2->next = new_node;
                tail2 = new_node;
            }
        }

        Solution obj;
        Node *result = obj.findIntersection(head1, head2);

        printList(result);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends