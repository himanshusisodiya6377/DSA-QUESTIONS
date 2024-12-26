class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        while(students.size()>0){
            int n=students.size();
            bool flag=false;
            for(int i=0;i<n;i++){
                if(students[0]==sandwiches[0]){
                    students.erase(students.begin());
                     sandwiches.erase(sandwiches.begin());
                     flag=true;
                }
                else{
                    int x=students[0];
                     students.erase(students.begin());
                     students.push_back(x);
                }
            }
             if(flag==false) break;
        }
        return students.size();
    }
};