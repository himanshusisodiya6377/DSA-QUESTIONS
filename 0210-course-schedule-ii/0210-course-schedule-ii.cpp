class Solution {
public:
    unordered_map<int, vector<int>> ls;
    void creatls(vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        for (int i = 0; i < n; i++) {
            ls[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
    }
    void khanalgo(int courses, vector<vector<int>>& prerequisites,
                  vector<int>& visit, int& count, vector<int>& ans) {
        vector<int> degree(courses, 0);
        for (int i = 0; i < prerequisites.size(); i++) {
            degree[prerequisites[i][1]]++;
        }
        queue<int> q;
        for (int i = 0; i < courses; i++) {
            if (degree[i] == 0) {
                q.push(i);
            }
        }
        // bfs
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            ans.push_back(x);
            count++;
            for (auto neigh : ls[x]) {
            
                    degree[neigh]--;
                    if (degree[neigh] == 0) {
                        q.push(neigh);
            
                
                }
            }
        }
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> visit(numCourses, 0);
        vector<int> ans;
        int count = 0;
        creatls(prerequisites);
        khanalgo(numCourses, prerequisites, visit, count, ans);
        if (count != numCourses)
            return {};
        reverse(begin(ans), end(ans));
        return ans;
    }
};