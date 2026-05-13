class Solution {
public:
    int check(vector<string>&a, vector<char>& letters, vector<int>& score){
        unordered_map<char,int>word;
        unordered_map<char,int>let;

        for(auto &it : a){
            for(auto &x : it) word[x]++;
        }

        for(auto &it : letters) let[it]++;

        for(auto &it : word){
            if(!let.count(it.first) || it.second>let[it.first]) return 0;
        }
        
        int sc=0;

        for(auto &it : word){
            sc+=(it.second*score[it.first-'a']);
        }

        return sc;

    }
    int solve(vector<string>& words, vector<char>& letters, vector<int>& score,int idx,vector<string>a){
        if(idx>=words.size()){
            return check(a,letters,score); 
        }

        a.push_back(words[idx]);
        int inc=solve(words,letters,score,idx+1,a);
        a.pop_back();
        int not_inc=solve(words,letters,score,idx+1,a);
        return max(inc,not_inc);
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int n=words.size();
        vector<string>a;
        a.push_back(words[0]);
        int inc=solve(words,letters,score,1,a);
        a.pop_back();
        int not_inc=solve(words,letters,score,1,a);
        return max(inc,not_inc);
    }
};