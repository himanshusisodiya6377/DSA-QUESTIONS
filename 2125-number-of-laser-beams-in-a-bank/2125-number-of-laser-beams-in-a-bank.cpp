class Solution {
public:
int security(string s){
    int n=s.length();
    int x=0;
    for(int i=0;i<n;i++){
        if(s[i]=='1') x++;
    }
    return x;
}
    int numberOfBeams(vector<string>& bank) {
        int n=bank.size();
        queue<int>q;
        int sum=0;
        for(int i=0;i<n;i++){
        int sec=security(bank[i]);
           if(sec!=0) q.push(sec);
        }
        while(q.size()>0){
            int x=q.front();
            q.pop();
            if(q.size()<=0) break;
            sum+=(x*q.front());
        }
        return sum;
    }
};