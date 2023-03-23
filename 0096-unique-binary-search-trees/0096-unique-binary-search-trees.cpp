class Solution {
public:
    long nCr(int n, int r){
        r = min(r, n - r);
        long res = 1;
        for (int i = 1; i <= r; i++)
        {
            res = (res * (n - r + i) / i);
        }
        return res;
    }
    int numTrees(int n) {
        return nCr(2 * n, n) / (n + 1);
    }
};