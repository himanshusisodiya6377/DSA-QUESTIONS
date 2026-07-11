class TrieNode {
public:
    TrieNode* child[26];
    int end;

    TrieNode() {
        memset(child, 0, sizeof(child));
        end = 0;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(string &word) {
        TrieNode* cur = root;

        for(char c : word) {
            int idx = c - 'a';

            if(!cur->child[idx])
                cur->child[idx] = new TrieNode();

            cur = cur->child[idx];
        }

        cur->end++;
    }

    int query(string &word) {
        TrieNode* cur = root;
        int ans = 0;
        int n = word.size();

        for(int i = 0; i < n; i++) {

            int idx = word[i] - 'a';

            if(!cur->child[idx])
                break;

            cur = cur->child[idx];

            if(cur->end) {

                int len = i + 1;
                bool ok = true;

                for(int j = 0; j < len; j++) {
                    if(word[j] != word[n - len + j]) {
                        ok = false;
                        break;
                    }
                }

                if(ok)
                    ans += cur->end;
            }
        }

        return ans;
    }
};

class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {

        Trie trie;
        int ans = 0;

        for(string &word : words) {
            ans += trie.query(word);
            trie.insert(word);
        }

        return ans;
    }
};