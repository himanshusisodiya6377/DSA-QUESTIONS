// User function Template for C++

class Solution {
  public:
     class Node {

    public:
        Node* links[2];
        bool flag;

        Node() {
            for (int i = 0; i < 2; i++)
                links[i] = NULL;
            flag = false;
        }
    };

    class Trie {
    public:
        Node* root;

        Trie() { root = new Node(); }

        void insert(int num) {
            Node* curr = root;

            for (int i = 31; i >= 0; i--) {
                int n = (num >> i) & 1;
                Node* node;
                if (curr->links[n] == NULL) {
                    node = new Node();
                    curr->links[n] = node;
                }
                curr = curr->links[n];
            }
            curr->flag = true;
        }

        int maxXor(int num) {
            Node* curr = root;
            int maxi = 0;
            for (int i = 31; i >= 0; i--) {
                int n = (num >> i) & 1;
                // cout<<n<<endl;
                int t;
                (n == 0 ? t = 1 : t = 0);
                Node* node;
                if (curr->links[t] == NULL) {
                    curr = curr->links[n];
                } else {
                    maxi = maxi | (1 << i);
                    curr = curr->links[t];
                }
            }

            return maxi;
        }
    };
    int maxSubarrayXOR(int N, int arr[]) {
        // code here
        int maxi=0;
        int xr=0;
        Trie*trie=new Trie();
        trie->insert(0);
        for(int i=0;i<N;i++){
            xr^=arr[i];
            trie->insert(xr);
            int num=trie->maxXor(xr);
            maxi=max(maxi,num);
        }
        
        return maxi;
    }
};