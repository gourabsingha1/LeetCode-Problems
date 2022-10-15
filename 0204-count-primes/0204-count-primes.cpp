class Solution {
public:
    int countPrimes(int n) {
        int res = 0;
        vector<bool> v(n,0);
        for (int i = 2; i < n; i++)
        {
            if(!v[i]){
                res++;
                v[i] = 1;
            }
            for (int j = i; j < n; j += i)
            {
                v[j] = 1;
            }
        }
        return res;
    }
};