class WordDictionary {
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
    
    WordDictionary() {
        root=new Node();
    }
    
    void addWord(string word) {
         Node*curr=root;
        for(int i=0;i<word.length();i++){
            Node*node;
           if(curr->arr[word[i]-'a']==NULL){
              node = new Node();
              curr->arr[word[i]-'a']=node;
           }
        curr=curr->arr[word[i]-'a'];
        }
        curr->flag=true;
    }
    
    bool check(string &word,int idx,Node*ch){
        
        if(idx>=word.length()) return ch->flag;
        Node*curr=ch;
        if(word[idx]=='.'){
            bool fg=false;
            for(auto &it : curr->arr){
                if(it!=NULL) fg=fg | check(word,idx+1,it);
            }

            return fg;
        }
        else{
            
           if(curr->arr[word[idx]-'a']==NULL) return false;

           return check(word,idx+1,curr->arr[word[idx]-'a']);
        }

        return false;
    }
    bool search(string word) {
        return check(word,0,root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */