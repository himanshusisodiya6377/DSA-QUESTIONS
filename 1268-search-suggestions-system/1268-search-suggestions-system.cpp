class Solution {
public:
    class Node {
    public:
        vector<Node*> arr;
        bool flag;
        vector<string> st;

        Node() {
            arr.resize(26, NULL);
            flag = false;
        }
    };
    class Trie {
    public:
        Node* root;

        Trie() { root = new Node(); }

        void insert(string word) {
            // iterate to each word
            Node* curr = root;
            for (int i = 0; i < word.length(); i++) {
                Node* node;
                if (curr->arr[word[i] - 'a'] == NULL) {
                    node = new Node();
                    curr->arr[word[i] - 'a'] = node;
                }
                curr = curr->arr[word[i] - 'a'];
                if((curr->st).size()<3) curr->st.push_back(word);
            }
            curr->flag = true;
        }

        vector<vector<string>> search(string word) {
            Node* curr = root;
            vector<vector<string>> ans;
            for (int i = 0; i < word.length(); i++) {
                vector<string> s;
                // if (curr->arr[word[i] - 'a'] == NULL)
                //     return {};
                if (curr == NULL || curr->arr[word[i] - 'a'] == NULL) {
                    ans.push_back({}); // Push an empty list
                    curr = NULL; // Force subsequent characters to also be empty
                } else {
                    curr = curr->arr[word[i] - 'a'];
                    // for(int j=0;j<min(3,(int)((curr->st).size()));j++){
                    //     s.push_back((curr->st)[j]);
                    // }
                    ans.push_back(curr->st);
                }
            }

            return ans;
        }

        // bool startsWith(string prefix) {
        //     Node* curr = root;
        //     for (int i = 0; i < prefix.length(); i++) {
        //         if (curr->arr[prefix[i] - 'a'] == NULL)
        //             return false;
        //         curr = curr->arr[prefix[i] - 'a'];
        //     }

        //     return true;
        // }
    };
    vector<vector<string>> suggestedProducts(vector<string>& products,
                                             string searchWord) {
        sort(products.begin(), products.end());
        Trie* trie = new Trie();

        for (auto& it : products)
            trie->insert(it);

        return trie->search(searchWord);
    }
};