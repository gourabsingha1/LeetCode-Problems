class Solution {
public:
    int integerBreak(int n) {
        if(n < 4){
            return n - 1;
        }
        int res = pow(3, n / 3);
        if(n % 3 == 1){
            res = (res / 3) * 4;
        }
        else if(n % 3 == 2){
            res *= 2;
        }
        return res;
    }
};