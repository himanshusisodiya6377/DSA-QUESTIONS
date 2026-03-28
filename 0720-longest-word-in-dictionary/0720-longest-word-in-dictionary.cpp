class Solution {
public:
    class Node {
    public:
        Node* arr[26];
        bool flag;

        Node() {
            for(int i = 0; i < 26; i++) arr[i] = NULL;
            flag = false;
        }
    };

    class Trie {
    public:
        Node* root;

        Trie() {
            root = new Node();
        }

        void insert(string word) {
            Node* curr = root;
            for(char c : word) {
                int idx = c - 'a';
                if(curr->arr[idx] == NULL)
                    curr->arr[idx] = new Node();

                curr = curr->arr[idx];
            }
            curr->flag = true;
        }
    };

    string ans = "";

    void dfs(Node* node, string curr) {
        // update answer
        if(curr.length() > ans.length() || 
           (curr.length() == ans.length() && curr < ans)) {
            ans = curr;
        }

        for(int i = 0; i < 26; i++) {
            if(node->arr[i] && node->arr[i]->flag) {
                dfs(node->arr[i], curr + char('a' + i));
            }
        }
    }

    string longestWord(vector<string>& words) {
        Trie trie;

        for(auto &w : words)
            trie.insert(w);

        dfs(trie.root, "");

        return ans;
    }
};