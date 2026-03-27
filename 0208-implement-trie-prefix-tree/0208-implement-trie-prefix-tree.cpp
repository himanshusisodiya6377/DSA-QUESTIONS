class Trie {
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

    Node*root;
    
    Trie() {
      root=new Node();    
    }
    
    void insert(string word) {
        //iterate to each word
        Node*curr=root;
        for(int i=0;i<word.length();i++){
            Node*node;
           if(curr->arr[word[i]-'a']==NULL){
              node = new Node();
              curr->arr[word[i]-'a']=node;
           }
        //    for(auto &it : root->arr){
        //     cout<<it<<" ";
        //    }
        //    cout<<endl;
           curr=curr->arr[word[i]-'a'];
        }
        // cout<<root->flag<<endl;
        curr->flag=true;
    }
    
    bool search(string word) {
        Node*curr=root;
        for(int i=0;i<word.length();i++){
            if(curr->arr[word[i]-'a']==NULL) return false;

            curr=curr->arr[word[i]-'a'];
        }

        return curr->flag;
    }
    
    bool startsWith(string prefix) {
        Node*curr=root;
        for(int i=0;i<prefix.length();i++){
            if(curr->arr[prefix[i]-'a']==NULL) return false;
            curr=curr->arr[prefix[i]-'a'];
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */