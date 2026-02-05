class Solution {
public:
    void deleteAllOccurOfX(struct Node** head, int x) {

        Node* curr = *head;

        // 1️⃣ Remove x from beginning
        while (curr != NULL && curr->data == x) {
            Node* del = curr;
            curr = curr->next;
            delete del;
        }

        if (curr == NULL) {
            *head = NULL;
            return;
        }

        curr->prev = NULL;
        *head = curr;

        // 2️⃣ Remove x from middle/end
        Node* temp = curr;

        while (temp != NULL && temp->next != NULL) {

            if (temp->next->data == x) {

                Node* del = temp->next;
                temp->next = del->next;

                if (del->next != NULL)
                    del->next->prev = temp;

                delete del;
            }
            else {
                temp = temp->next;
            }
        }
    }
};
