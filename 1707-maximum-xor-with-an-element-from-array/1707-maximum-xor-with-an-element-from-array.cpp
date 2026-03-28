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
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(), nums.end());
        
         vector<vector<int>> q;
        for(int i = 0; i < queries.size(); i++){
            q.push_back({queries[i][0], queries[i][1], i});
        }

        sort(q.begin(), q.end(), [](auto &a, auto &b){
            return a[1] < b[1];
        });



        Trie*trie=new Trie();

        vector<int>ans(q.size(),0);
        int i=0,j=0;

        for(auto &it : q){
            int x=it[0];
            int y=it[1];
            int idx=it[2];

            if(nums.size()==0 || y<nums[0]) {
                ans[idx]=-1;
                continue;
            }

            while(i<nums.size() && nums[i]<=y){
               trie->insert(nums[i]);
               i++;
            }

            

            int num=trie->maxXor(x);
            // cout<<x<<" "<<num<<endl;
            ans[idx]=num;
            j++;
        }

        return ans;
    }
};