class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n=changed.size();
        if(n%2!=0) return {};
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++) mp[changed[i]]++;
        vector<int>ans;
        sort(changed.begin(),changed.end());
        for(int i=0;i<n;i++){
            if(mp[changed[i]]==0) continue;
            if (mp[changed[i] * 2] == 0) return {};
            
            ans.push_back(changed[i]);
            mp[changed[i]]--;        
            mp[changed[i]* 2]--;    
            // if(changed[i]%2!=0){
            //     if(mp.find(2*changed[i])!=mp.end()){
            //        if(mp[2*changed[i]]>0 && mp[changed[i]]>0) ans.push_back(changed[i]);
            //         mp[2*changed[i]]--;
            //          mp[changed[i]]--;
            //         // if(mp[2*changed[i]]==0) mp.erase(2*changed[i]);
                    // if(mp[changed[i]]==0) mp.erase(changed[i]);
            //     }
            //     else return {};
            // }
            // else{
            //     if(mp.find(2*changed[i])!=mp.end()){
            //         if(mp[2*changed[i]]>0 && mp[changed[i]]>0)  ans.push_back(changed[i]);
            //         mp[2*changed[i]]--;
            //           mp[changed[i]]--;
                    // if(mp[changed[i]]==0) mp.erase(changed[i]);
                    // if(mp[2*changed[i]]==0) mp.erase(2*changed[i]);
                //}
                // else if(mp.find(changed[i]/2)!=mp.end()){
                //     if(mp[changed[i]/2]>0) ans.push_back(changed[i]);
                //     mp[changed[i]/2]--;
                //      mp[changed[i]]--;
                //     // if(mp[changed[i]]==0) mp.erase(changed[i]);
                //     // if(mp[changed[i]/2]==0) mp.erase(changed[i]/2);
                // }
                // else return {};
            }
        
        return ans;
    }
};