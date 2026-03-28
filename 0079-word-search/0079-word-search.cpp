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
                if(curr->arr[word[i]-'A']==NULL){
                    node=new Node();
                    curr->arr[word[i]-'A']=node;
                }
                curr=curr->arr[word[i]-'A'];
            }
            curr->flag=true;
        }
    };

    bool check(vector<vector<char>>& board,int r,int c,int i,int j,Node*node){
         if(node == NULL) return false;
        if(i<0 || i>=r || j<0 || j>=c || board[i][j]=='#') return false;
        // if(idx>=word.length()) return true;
        if(node->arr[board[i][j]-'A']==NULL) return false;

        Node*newnode=node->arr[board[i][j]-'A'];
        if(newnode->flag) return true;
        bool flag=false;
        char ch=board[i][j];
        board[i][j]='#';
        flag=flag || check(board,r,c,i,j+1,newnode);
        flag=flag || check(board,r,c,i+1,j,newnode);
        flag=flag || check(board,r,c,i-1,j,newnode);
        flag=flag || check(board,r,c,i,j-1,newnode);
        
        board[i][j]=ch;
        return flag;
    }
    bool exist(vector<vector<char>>& board, string word) {
        Trie*trie=new Trie();
        trie->insert(word);

        int r=board.size();
        int c=board[0].size();
        
        bool flag=false;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
               if(board[i][j]==word[0]){
                char ch=board[i][j];
                board[i][j]='#';
               flag=flag || check(board,r,c,i,j+1,trie->root->arr[word[0]-'A']);
               flag=flag || check(board,r,c,i+1,j,trie->root->arr[word[0]-'A']);
               flag=flag || check(board,r,c,i-1,j,trie->root->arr[word[0]-'A']);
               flag=flag || check(board,r,c,i,j-1,trie->root->arr[word[0]-'A']);

               board[i][j]=ch;

               if(flag) return true;
               }
            }
        }

        return flag;
    }
};