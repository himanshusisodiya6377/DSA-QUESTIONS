class Solution {
public:

    
    vector<string>lowerword;
    vector<string>lowerquerie;


    string to_lower(string s) {
    for (char &c : s) {
        c = tolower(c);  
    }
    return s;
    }

    bool same(string &temp,string &get){
        if(temp.length()!=get.length()) return false;

        int i=0;
        while(i<temp.length()){
            if(temp[i]!=get[i] && ((temp[i]=='a' || temp[i]=='e' || temp[i]=='i' || temp[i]=='o' || temp[i]=='u') && (get[i]=='a' || get[i]=='e' || get[i]=='i' || get[i]=='o' || get[i]=='u')))
        {
            i++;
            // j++;
        }
        else if(temp[i]!=get[i]){
            return false;
        }
        else{
            i++;
            // j++
        }
        }
        return true;
    }

    string solve(vector<string>& wordlist,string check,string l){
        //checking if similar will get
        for(int i=0;i<wordlist.size();i++){
            if(wordlist[i]==check) return wordlist[i];
        }

        //checking capitalization
            // string get=to_lower(check);
        for(int i=0;i<wordlist.size();i++){
            if(lowerword[i]==l) return wordlist[i];
        }

        //checking vowel

        for(int i=0;i<wordlist.size();i++){
            if(same(lowerword[i],l)) return wordlist[i];
        }

        return "";
    } 
  
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        int w=wordlist.size();
        int q=queries.size();
        vector<string>ans(q,"");
        for(int i=0;i<w;i++) lowerword.push_back(to_lower(wordlist[i]));
        for(int i=0;i<q;i++) lowerquerie.push_back(to_lower(queries[i]));
        for(int i=0;i<q;i++){
             ans[i]=solve(wordlist,queries[i],lowerquerie[i]);
        }
        return ans;
    }
};