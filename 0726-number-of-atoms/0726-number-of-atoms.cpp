class Solution {
public:
    string countOfAtoms(string form) {
        int n=form.size();

        stack<pair<string,int>>st;

        // int i=0;
        string ele="";
        int num=0;

        for(int i=0;i<n;i++){
           if(isdigit(form[i])) {
            num=num*10+(form[i]-'0');
             if(i<n-1 && !isdigit(form[i+1]) && ele!=""){
                (num==0 ? st.push({ele,1}) : st.push({ele,num}));
                // cout<<ele<<" "<<num<<endl;
                num=0;
                ele="";
             }
           }
           else if(!isdigit(form[i]) && form[i]!='(' && form[i]!=')'){
              ele.push_back(form[i]);
              if(i<n-1 && (!isdigit(form[i+1]) && form[i+1]<97)){
                (num==0 ? st.push({ele,1}) : st.push({ele,num}));
                // cout<<ele<<" "<<num<<endl;
                num=0;
                ele="";
              }
           }
           else if(form[i]=='('){
            if(ele!=""){
                (num==0 ? st.push({ele,1}) : st.push({ele,num}));
                // cout<<ele<<" "<<num<<endl;
                num=0;
                ele="";
            }
                st.push({"(",0});
           }
           else{
              //closing milla he
               i++;
               int val=0;
               while(i<n && isdigit(form[i])){
                val=val*10+(form[i]-'0');
                i++;
               }

            //    if(val==0) continue;
               //decrease as above we increase
               i--;

               //handling
               stack<pair<string,int>>temp;

               while(!st.empty() && st.top().first!="("){
                val!=0 ? temp.push({st.top().first,st.top().second*val}) : temp.push({st.top().first,st.top().second});
                st.pop();
               }

               st.pop();

                while(!temp.empty()){
                st.push({temp.top().first,temp.top().second});
                temp.pop();
               }
           }
        }

        if(ele!=""){
             (num==0 ? st.push({ele,1}) : st.push({ele,num}));
        }

        // vector<pair<string,int>>v;
        map<string,int>mp;
        
        while(!st.empty()){
            // cout<<st.top().first<<" "<<st.top().second<<endl;
            mp[st.top().first]+=st.top().second;
            st.pop();
        }

        // sort(v.begin(),v.end());

        string ans="";

        // for(int i=0;i<v.size();i++){
        //     ans+=v[i].first;
        //     if(v[i].second!=1) ans+=to_string(v[i].second);
        // }

        for(auto &it : mp){
            ans+=it.first;
            if(it.second!=1) ans+=to_string(it.second);
        }

     return ans;
    }
    
};