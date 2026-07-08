class Solution {
public:
    int maxPalindromesAfterOperations(vector<string>& words) {
        vector<pair<int,string>>v;

        for(auto &it : words){
            v.push_back({it.length(),it});
        }
        sort(v.begin(),v.end());

        vector<int>freq(26,0);

        for(auto &it : words){
            for(auto &x : it){
                freq[x-'a']++;
            }
        }

        int even=0,odd=0;

        for(int i=0;i<26;i++){
            even+=freq[i]/2;
            odd+=freq[i]%2;
        }

        cout<<even<<" "<<odd<<endl;

        int ans=0;

        for(auto &x : v){
            auto it=x.second;
            int len=it.size();
            // cout<<len<<endl;
            
            int even_want=len/2;
            int odd_want=len%2;

            if(even<even_want){
                  break;
            }
            else if(odd<odd_want){
                  if(even>0){
                    even--;
                    odd++;
                    ans++;
                  }
                  else break;
            }else {
                even-=even_want;
                odd-=odd_want;
                ans++;
            }
        }

        return ans;
    }
};