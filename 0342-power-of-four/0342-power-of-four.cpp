class Solution {
public:
    bool isPowerOfFour(int n) {
        return n != INT_MIN && __builtin_popcount(n) == 1 && int(log2(n)) % 2 == 0;
    }
};