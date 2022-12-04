class Solution {
public:
    double recur(double x, int n) {
        if(!x) return 0;
        if(!n) return 1;
        double res = recur(x, n/2);
        res *= res;
        if(n&1) res *= x;
        return res;
    }
    double myPow(double x, int n) {
        if(n == INT_MIN){
            if(abs(x)==1) return 1;
            return 0;
        }
        if(n < 0) return 1/recur(x, -n);
        return recur(x, n);
    }
};