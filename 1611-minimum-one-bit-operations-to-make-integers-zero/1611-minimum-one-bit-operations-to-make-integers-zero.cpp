// n = 2^k, takes 2^(k + 1) - 1 operations
// minimumOneBitOperations(1000) = minimumOneBitOperations(1010) + minimumOneBitOperations(10)
// minimumOneBitOperations(1010) = minimumOneBitOperations(1000) - minimumOneBitOperations(10)

class Solution {
public:
    int minimumOneBitOperations(int n) {
        if(n <= 1) {
            return n;
        }

        int bits = log2(n) + 1;
        int ub = 1 << bits, lb = 1 << (bits - 1);
        return (ub - 1) - minimumOneBitOperations(n - lb);
    }
};