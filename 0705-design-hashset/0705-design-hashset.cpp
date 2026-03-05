class MyHashSet {
public:
    vector<list<int>>v;
    int N=1e6+1;
    MyHashSet() {
        v.resize(N,list<int>{});
    }
    
    void add(int key) {
        int index=key%N;
        auto it=find(v[index].begin(),v[index].end(),index);

        if(it==v[index].end()) v[index].push_back(key);
    }
    
    void remove(int key) {
        int index=key%N;
        // auto it=find(v[index].begin(),v[index].end(),index);
       for(auto it = v[index].begin(); it != v[index].end(); ){
    if(*it == key)
        it = v[index].erase(it);
    else
        ++it;
}
        // if(it!=v[index].end()) v.erase(it);
    }
    
    bool contains(int key) {
        int index=key%N;
         auto it=find(v[index].begin(),v[index].end(),index);
         return it!=v[index].end();
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */