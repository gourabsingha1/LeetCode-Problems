class Solution {
public:
    int clumsy(int n) {
        int res = n + 2;
        if(n < 3) res = n;
        else if(n == 3) res = 6;
        else if(n == 4) res = 7;
        else if(n % 4 == 0) res = n + 1;
        else if(n % 4 == 3) res = n - 1;
        return res;
    }
};