class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n=classes.size();
        // int sum=0;
        priority_queue<pair<double,double>>pq;
        for(int i=0;i<n;i++){
            double rat=(double)classes[i][0]/classes[i][1];
            double fut=(double)(classes[i][0]+1)/(classes[i][1]+1);
            double diff=fut-rat;
            // sum+=rat;
            pq.push({diff,i});
        }

        while(extraStudents>0){
             pair<int,int>p=pq.top();
             pq.pop();
             classes[p.second][0]++;
             classes[p.second][1]++;
             double rat=(double)classes[p.second][0]/classes[p.second][1];
             double fut=(double)(classes[p.second][0]+1)/(classes[p.second][1]+1);
             double diff=fut-rat;
            // sum+=rat;
            pq.push({diff,p.second});
            extraStudents--;
        }

        double sum=0;
        for(int i=0;i<n;i++){
            double rat=(double)classes[i][0]/classes[i][1];
            sum+=rat;
        }

        return sum/n;
    }
};