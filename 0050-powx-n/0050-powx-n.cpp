class Solution {
public:
    double exp(double x, int n){
        double res = 1;
        while(n){
            if(n & 1) {
                if(n > 0) {
                    res *= x;
                }
                else {
                    res /= x;
                }
            }
            x *= x;
            n /= 2;
        }
        return res;
    }
    
    double myPow(double x, int n) {
        return exp(x, n);
    }
};