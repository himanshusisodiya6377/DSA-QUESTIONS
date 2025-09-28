class TaskManager {
public:
    
    unordered_map<int,set<pair<int,int>>>mp;
    unordered_map<int,int>prio;
    unordered_map<int,int>task;
    set<pair<int,int>>high;

    TaskManager(vector<vector<int>>& tasks) {

        //O(n)
        for(auto it : tasks){
         mp[it[0]].insert({it[2],it[1]});
         prio[it[1]]=it[2];
         task[it[1]]=it[0];
         high.insert({it[2],it[1]});
        }

    }
    
    void add(int userId, int taskId, int priority) {

        //O(1)
        mp[userId].insert({priority,taskId});
        prio[taskId]=priority;
        task[taskId]=userId;
        high.insert({priority,taskId});

    }
    
    void edit(int taskId, int newPriority) {

        //O(1)
        int old=prio[taskId];
        int user=task[taskId];
        mp[user].erase({old,taskId});
        prio[taskId]=newPriority;
        mp[user].insert({newPriority,taskId});
        high.erase({old,taskId});
        high.insert({newPriority,taskId});

    }
    
    void rmv(int taskId) {

        //O(1)
       int user=task[taskId];
       int pr=prio[taskId];
       mp[user].erase({pr,taskId});
       task.erase(taskId);
       prio.erase(taskId);
       high.erase({pr,taskId});

    }
    
    int execTop() {

        int taski=-1;
        int user=-1;
        int pr=-1;

        //O(1)
        if(!high.empty()){
        taski=rbegin(high)->second;
        user=task[taski];
        pr=rbegin(high)->first;
        }
        

        if(pr==-1) return -1;
        
        mp[user].erase({pr,taski});
        prio.erase(taski);
        task.erase(taski);
        high.erase({pr,taski});

        return user;

    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */