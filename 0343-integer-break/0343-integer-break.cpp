class Solution {
public:
    int integerBreak(int n) {
        if(n < 4) {
            return n - 1;
        }
        
        int res = n % 3;
        n -= res;
        if(res == 0) {
            res = 1;
        }
        else if(res == 1) {
            res += 3;
            n -= 3;
        }
        while(n) {
            res *= 3;
            n -= 3;
        }
        return res;
    }
};