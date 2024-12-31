//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position) {
    if (position == 0)
        return;

    Node* walk = head;
    for (int i = 1; i < position; i++)
        walk = walk->next;
    tail->next = walk;
}

bool isLoop(Node* head) {
    if (!head)
        return false;

    Node* fast = head->next;
    Node* slow = head;

    while (fast != slow) {
        if (!fast || !fast->next)
            return false;
        fast = fast->next->next;
        slow = slow->next;
    }

    return true;
}

int length(Node* head) {
    int ret = 0;
    while (head) {
        ret++;
        head = head->next;
    }
    return ret;
}

bool notOriginal(Node* head, unordered_map<Node*, int>& myMap) {

    while (head) {
        if (myMap.find(head) == myMap.end())
            return true;
        if (myMap[head] != (head->data))
            return true;

        head = head->next;
    }
}


// } Driver Code Ends

class Solution {
  public:
    // Function to remove a loop in the linked list.
    void removeLoop(Node* head) {
       if(head==NULL || head->next==NULL) return ;
        Node*temp=head;
        Node*s=head->next; 
        Node*t=head->next->next;
        bool flag=false;
        while(t!=NULL && t->next!=NULL){
            if(s==t){
                flag=true;
                break;
            }
            else{
                s=s->next;
                t=t->next->next;
            }
        }
        if(flag==true){
            while(temp!=s){
                temp=temp->next;
                s=s->next;
            }
        }
        else return;
        while(t->next!=temp) t=t->next;
        t->next=NULL;
        return;
    }
};
/*
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL || head->next==NULL) return NULL;
        ListNode*temp=head;
        ListNode*s=head->next; 
        ListNode*t=head->next->next;
        bool flag=false;
        while(t!=NULL && t->next!=NULL){
            if(s==t){
                flag=true;
                break;
            }
            else{
                s=s->next;
                t=t->next->next;
            }
        }
        if(flag==true){
            while(temp!=s){
                temp=temp->next;
                s=s->next;
            }
            return temp;
        }
        else return NULL;
    }
};
*/

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        unordered_map<Node*, int> myMap;

        int n, num;
        n = arr.size();

        Node *head, *tail;
        num = arr[0];
        head = tail = new Node(num);

        myMap[head] = num;

        for (int i = 1; i < n; i++) {
            num = arr[i];
            tail->next = new Node(num);
            tail = tail->next;
            myMap[tail] = num;
        }

        int pos;
        cin >> pos;
        cin.ignore();
        loopHere(head, tail, pos);

        Solution ob;
        ob.removeLoop(head);

        if (isLoop(head) || length(head) != n || notOriginal(head, myMap))
            cout << "false\n";
        else
            cout << "true\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends