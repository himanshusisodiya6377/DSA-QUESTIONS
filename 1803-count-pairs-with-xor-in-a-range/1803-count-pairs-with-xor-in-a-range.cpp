class Solution {
public:
    class Node {

    public:
        Node* links[2];
        bool flag;
        int cnt;

        Node() {
            for (int i = 0; i < 2; i++)
                links[i] = NULL;
            flag = false;
            cnt=0;
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
                curr->cnt++;
            }
            curr->flag = true;
        }

        int maxPair(int num,int k){
            int pairs=0;
            Node*curr=root;

            for(int i=31;i>=0 && curr;i--){

                int bit_num=(num>>i)&1;
                int bit_k=(k>>i)&1;

                if(bit_k==1){
                    if(curr->links[bit_num]!=NULL){
                         pairs+=curr->links[bit_num]->cnt;
                    }
                    curr=curr->links[1-bit_num];
                }
                else{
                    curr=curr->links[bit_num];
                }
            }

            if(curr) pairs+=curr->cnt;

            return pairs;
        }

        void deleteTrie(Node*root){
            if(root==NULL) return;

            for(int i=0;i<2;i++){
                deleteTrie(root->links[i]);
                delete root->links[i];
            }
        }
    };
    int countPairs(vector<int>& nums, int low, int high) {
        
        Trie*trie=new Trie();

        int cnt=0;
        int n=nums.size();
        int cnt1=0;

        for(int i=0;i<n;i++){
            cnt+=trie->maxPair(nums[i],high);
            cnt-=trie->maxPair(nums[i],low-1);
            trie->insert(nums[i]); 
        }

        // trie->deleteTrie(trie->root);
       
        // for(int i=0;i<n;i++){
        //     cnt1+=trie->maxPair(nums[i],high);
        //     trie->insert(nums[i]); 
        // }

        return cnt;
    }
};