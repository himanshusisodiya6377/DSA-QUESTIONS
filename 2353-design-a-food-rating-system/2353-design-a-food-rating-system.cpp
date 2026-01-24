class FoodRatings {
public:
    typedef pair<int,string> p;
    struct cmp{
      bool operator()(const p&a,const p&b)const{
        if(a.first==b.first){
            return a.second>b.second;
        }
        return a.first<b.first;
      }
    };
    unordered_map<string,int>rating; //food --> rating
    unordered_map<string,priority_queue<p,vector<p>,cmp>>cousine;
    unordered_map<string,string>mp; //food --> cuisines
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        
        int n=foods.size();
        for(int i=0;i<n;i++){
            rating[foods[i]]=ratings[i];
            cousine[cuisines[i]].push({ratings[i],foods[i]});
            mp[foods[i]]=cuisines[i];
        }

    }
    
    void changeRating(string food, int newRating) {
        rating[food]=newRating;
        cousine[mp[food]].push({newRating,food});
    }
    
    string highestRated(string cuisine) {
        while(!cousine[cuisine].empty()){
            auto p=cousine[cuisine].top();
            if(p.first!=rating[p.second]) cousine[cuisine].pop();
            else break;
        }
        return cousine[cuisine].top().second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */