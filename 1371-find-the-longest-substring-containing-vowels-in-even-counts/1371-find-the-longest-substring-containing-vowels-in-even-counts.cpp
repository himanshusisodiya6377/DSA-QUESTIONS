class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n=s.length();
        map<vector<int>,int>mp;
        mp[{0,0,0,0,0}]=-1;
        vector<int>freq(5,0);
        int len=0;

        for(int i=0;i<n;i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
                if(s[i]=='a'){
                    freq[0]++;
                    freq[0]=freq[0]%2;
                }
                else if(s[i]=='e'){
                    freq[1]++;
                    freq[1]=freq[1]%2;
                }
                else if(s[i]=='i'){
                    freq[2]++;
                    freq[2]=freq[2]%2;
                }
                else if(s[i]=='o'){
                    freq[3]++;
                    freq[3]=freq[3]%2;
                }
                else if(s[i]=='u'){
                    freq[4]++;
                    freq[4]=freq[4]%2;
                }
            }

            // for(auto &it : freq) cout<<it<<" ";
            // cout<<endl;

            if(mp.find(freq)!=mp.end()){
                len=max(len,i-mp[freq]);
            }

            if(mp.find(freq)==mp.end()) mp[freq]=i;
        }

        //  len=max(len,i-mp[freq]);

        return len;
    }
};