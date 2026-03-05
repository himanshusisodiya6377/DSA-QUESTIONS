class MyHashMap {
public:
    vector<vector<int>>ans;
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        bool fg=false;
        for(auto &it : ans){
            if(it[0]==key) {
                it[1]=value;
                fg=true;
                break;
            }
        }

        if(!fg) ans.push_back({key,value});
    }
    
    int get(int key) {
        for(auto &it : ans){
            if(it[0]==key) return it[1];
        }
        return -1;
    }
    
    void remove(int key) {
        for(auto &it : ans){
            if(it[0]==key){
                it[0]=-1;
                it[1]=-1;
                break;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */