// bitmask

class Solution {
public:
    int helper(int i, int n, int seen){
        if(i > n){
            return 1;
        }
        
        int res = 0;
        for (int j = 1; j <= n; j++)
        {
            int bit = 1 << (j - 1);
            if(seen & bit) continue;
            if(i % j == 0 || j % i == 0) {
                res = res + helper(i + 1, n, seen | bit);
            }
        }
        return res;
    }

    int countArrangement(int n) {
        return helper(1, n, 0);
    }
};