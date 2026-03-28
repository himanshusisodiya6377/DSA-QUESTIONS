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
        public:
        Node*root;
        Trie(){
            root=new Node();
        }

        void insert(string &word){

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
    };

    vector<string>ans;
    void check(vector<vector<char>>& board,int r,int c,int i,int j,Node*node,string s){
        //  if(node == NULL) return ;
        if(i<0 || i>=r || j<0 || j>=c || board[i][j]=='#') return ;
        // if(idx>=word.length()) return true;
        if(node->arr[board[i][j]-'a']==NULL) return ;

        Node*newnode=node->arr[board[i][j]-'a'];
        char ch=board[i][j];
        s.push_back(ch);
        if(newnode->flag) {
            ans.push_back(s);
            newnode->flag=false;
        }

        // bool flag=false;
        board[i][j]='#';
        check(board,r,c,i,j+1,newnode,s);
        check(board,r,c,i+1,j,newnode,s);
        check(board,r,c,i-1,j,newnode,s);
        check(board,r,c,i,j-1,newnode,s);

        s.pop_back();
        
        board[i][j]=ch;
        // return flag;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& word) {
        
        Trie*trie=new Trie();

        for(auto &it : word){
            trie->insert(it);
        }


        int r=board.size();
        int c=board[0].size();

        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
               string s="";
               check(board,r,c,i,j,trie->root,s);
            }
        }

        return ans;
    }
};