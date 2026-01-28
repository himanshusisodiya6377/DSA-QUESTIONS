class LRUCache {
public:
    list<int>dll;
    int sz;
    unordered_map<int,pair<list<int>::iterator,int>>mp;
    LRUCache(int capacity) {
        sz=capacity;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()) return -1;
        
        dll.erase(mp[key].first);
        dll.push_front(key);
        mp[key].first=dll.begin();

        return mp[key].second;
    }
    
    void put(int key, int value) {
        
        if(mp.find(key)==mp.end()){
            dll.push_front(key);
            mp[key]={dll.begin(),value};
            sz--;
        }
        else{
            dll.erase(mp[key].first);
            dll.push_front(key);
            mp[key]={dll.begin(),value};
        }

        if(sz<0){
            auto it=dll.back();
            mp.erase(it);

            dll.pop_back();
            sz++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */