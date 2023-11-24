// if bits are same, make both bits set
// else by making the greater num's bit unset and smallers set
// we bring the nums closer

class Solution {
public:
    int maximumXorProduct(long long a, long long b, int n) {
        int M = 1e9 + 7;
        for (int i = n - 1; i >= 0; i--)
        {
            bool aBit = (a >> i) & 1, bBit = (b >> i) & 1;
            long long mask = (1LL << i);
            
            if(aBit == 0 && bBit == 0) {
                // make both bits set
                a |= mask, b |= mask;
            }
            else if(aBit != bBit) {
                if(a > b) {
                    // make aBit unset and bBit set
                    a &= (~mask);
                    b |= mask;
                }
                else {
                    a |= mask;
                    b &= (~mask);
                }
            }
        }
        return ((a % M) * (b % M)) % M;
    }
};