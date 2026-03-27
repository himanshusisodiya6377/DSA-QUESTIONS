class Solution {
public:
    class Node{
        public:
        vector<Node*>arr;
        bool flag;
        Node(){
           arr.resize(26,NULL);
           flag=false;
        }
    };

    class Trie{
        Node*root;
        public:
        Trie(){
            root=new Node();
        }

        void insert(string word){

            Node*curr=root;
            for(int i=0;i<word.length();i++){
                Node*node;
                if(curr->arr[word[i]-'a']==NULL){
                    node=new Node();
                    curr->arr[word[i]-'a']=node;
                }
                curr=curr->arr[word[i]-'a'];
            }
            curr->flag=true;
        }

        bool check(string word){
            Node*curr=root;

            for(int i=0;i<word.length();i++){
                Node*node;
                if(curr->arr[word[i]-'a']==NULL) return false;
                curr=curr->arr[word[i]-'a'];
            }

            return curr->flag;
        }

        bool prefix(string word){
            Node*curr=root;
            for(int i=0;i<word.length();i++){
                if(curr->arr[word[i]-'a']==NULL) return false;
                curr=curr->arr[word[i]-'a'];
            }
            return true;
        }

        string pre(string word){
            string ans="";
            Node*curr=root;
            for(int i=0;i<word.length();i++){
                if(curr->arr[word[i]-'a']==NULL) return "";
                ans.push_back(word[i]);
                curr=curr->arr[word[i]-'a'];
                if(curr->flag) return ans;
            }
            if(curr->flag) return ans;
            return ans;
        }
    };
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie* trie=new Trie();
        
        //inserting in trie
        for(auto &it : dictionary){
            trie->insert(it);
        }

        stringstream ss(sentence);
        string word;
        
        string ans="";
        while (ss >> word) {
            string s=trie->pre(word);
            (s=="" ? ans+=word : ans+=s);
            ans+=" ";
        }

        return ans.substr(0,ans.length()-1);
    }
};