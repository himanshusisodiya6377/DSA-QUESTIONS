class Solution {
public:
    bool isprime(int n) {
        // if(n==2) return true;
        if (n == 1)
            return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0)
                return false;
            ;
        }
        return true;
    }
    vector<int> closestPrimes(int left, int right) {
        int prime = -1;
        int diff = INT_MAX;
        for (int i = left; i <= right; i++) {
            if (isprime(i)) {
                prime = i;
                break;
            }
        }
        vector<int> v;
        if (prime == 2) {
            v.push_back(2);
            v.push_back(3);
        }
        else if(prime==-1){
            v.push_back(-1);
            v.push_back(-1);
        } 
        else {
            int j = 1;
            int secprime = -1;

            int temp = -1;

            while (secprime < right) {
                secprime = prime + 2 * j;
                if (isprime(secprime) && secprime <= right) {
                    int diff1 = secprime - prime;
                    if (diff > diff1)
                        diff = diff1;
                    temp = prime;
                    prime = secprime;
                    j = 0;
                }
                if (diff == 2)
                    break;
                j++;
            }
            if (diff == INT_MAX) {
                temp = -1;
                prime = -1;
            }
            v.push_back(temp);
            v.push_back(prime);
        }

        return v;
    }
};