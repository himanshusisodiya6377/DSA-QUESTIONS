class Solution {
public:
   
    int solve(int a,int b){
        string c=to_string(a);
        string d=to_string(b);
        int maxi=0;
        if(c.length()==d.length()){
            int cnt=0;
            for(int i=0;i<c.length();i++){
                if(c[i]==d[i]) cnt++;
                else break;
            }
            maxi=max(maxi,cnt);
        }
        else if(c.length()<d.length()){
            int cnt=0;
            for(int i=0;i<c.length();i++){
                if(c[i]==d[i]) cnt++;
            }
            maxi=max(maxi,cnt);
        }
        else{
            int cnt=0;
            for(int i=0;i<d.length();i++){
                if(c[i]==d[i]) cnt++;
                else break;
            }
            maxi=max(maxi,cnt);
        }

        return maxi;

    }
  
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n=arr1.size();
        int m=arr2.size();
        int maxi=0;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         int cal=solve(arr1[i],arr2[j]);
        //         maxi=max(maxi,cal);
        //     }
        // }
        unordered_set<string>st;
        for(int i=0;i<n;i++){
            string arr=to_string(arr1[i]);
            string ans="";
            for(int j=0;j<arr.length();j++){
                ans.push_back(arr[j]);
                st.insert(ans);
            }
        }

        for(int i=0;i<m;i++){
            string arr=to_string(arr2[i]);
            string ans="";
            for(int j=0;j<arr.length();j++){
                ans.push_back(arr[j]);
                if(st.find(ans)!=st.end()) maxi=max(maxi,(int)ans.length());
                else break;
            }
        }

        return maxi;
    }
};