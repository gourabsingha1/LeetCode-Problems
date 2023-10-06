class Solution {
public:
    int integerBreak(int n) {
        if(n < 4) {
            return n - 1;
        }
        
        int exp = pow(3, n / 3);
        if(n % 3 == 0) {
            return exp;
        }
        else if(n % 3 == 1) {
            return 4 * (exp / 3);
        }
        return 2 * exp;
    }
};