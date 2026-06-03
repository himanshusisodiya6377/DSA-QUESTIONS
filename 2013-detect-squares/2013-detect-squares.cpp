class DetectSquares {
public:
    map<vector<int>,int>mp;
    vector<vector<int>>points;

    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        mp[point]++;
        points.push_back(point);
    }
    
    int count(vector<int> point) {
    int x = point[0];
    int y = point[1];

    int ans = 0;

    for(auto &p : points) {
        int x1 = p[0];
        int y1 = p[1];

        if(x == x1 || y == y1)
            continue;

        if(abs(x - x1) != abs(y - y1))
            continue;

        ans += mp[{x, y1}] * mp[{x1, y}];
    }

    return ans;
}
    
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */