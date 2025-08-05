class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n=wordList.size();

        unordered_set<string>st(wordList.begin(),wordList.end());
        
        st.insert(beginWord);


        if(st.find(endWord) == st.end()) return 0;

        
        //creating graph
        unordered_map<string,vector<string>>adj;

        for (string word : st) {
            string original = word;
            for (int j = 0; j < word.size(); j++) {
                char ch = word[j];
                for (int k = 0; k < 26; k++) {
                    word[j] = 'a' + k;
                    if (st.find(word) != st.end() && word != original)
                        adj[original].push_back(word);
                }
                word[j] = ch;
            }
        }

        int req=1;

        queue<string>q;
        q.push(beginWord);
  
        set<string>visit;
        visit.insert(beginWord);

        while(!q.empty()){
       
        int m=q.size();

        for(int i=0;i<m;i++){
            string get=q.front();
            q.pop();
            
            if(get==endWord) return req;

            for(auto it : adj[get]){
                if(visit.find(it)==visit.end()){
                  q.push(it);
                  visit.insert(it);
                }
            }
           
        }

        req++; 

        }

      return 0;


    }
};