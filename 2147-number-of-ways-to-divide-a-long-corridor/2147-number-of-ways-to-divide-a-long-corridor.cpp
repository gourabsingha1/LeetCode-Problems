class Solution {
public:
    int numberOfWays(string corridor) {
        int res = 1, s = 0, n = corridor.size(), M = 1e9 + 7;
        for (int i = 0; i < n; i++)
        {
            int p = 1;
            while(s && s % 2 == 0 && i < n && corridor[i] == 'P') {
                i++, p++;
            }
            if(i < n) {
                res = (1LL * res * p) % M;
                s += corridor[i] == 'S';
            }
        }
        if(s == 0 || s & 1) res = 0;
        return res;
    }
};