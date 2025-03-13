class ProductOfNumbers {
public:
vector<int>v;
int key=1;
    ProductOfNumbers() {}
    
    void add(int num) {
        v.push_back(num);
    }
    
    int getProduct(int k) {
        int m=k;
        for(int i=v.size()-1;i>=0 && m>0;i--){
            key*=v[i];
            m--;
        }
        int ans=key;
        key=1;
        return ans;
    }
};
