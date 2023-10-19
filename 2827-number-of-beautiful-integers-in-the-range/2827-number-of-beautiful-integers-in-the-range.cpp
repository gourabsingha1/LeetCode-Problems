// leading zero can't be treated as even
// zero = 1 means leading zero

class Solution {
public:
    // pos, tight, rem, odd, even, zero
    int dp[10][2][20][10][10][2];

    int helper(string& s, int& k, int pos = 0, bool tight = 1, int rem = 0, int odd = 0, int even = 0, bool zero = 1) {
        if(pos == s.size()) {
            return rem == 0 && odd == even && !zero;
        }
        if(dp[pos][tight][rem][odd][even][zero] != -1) {
            return dp[pos][tight][rem][odd][even][zero];
        }

        int res = 0;
        if(tight == 1) {
            for (int i = 0; i <= s[pos] - '0'; i++)
            {
                if(i == s[pos] - '0') {
                    res += helper(s, k, pos + 1, 1, (rem * 10 + i) % k, odd + i % 2, even + ((i % 2 == 0) && (!zero || i != 0)), zero & (i == 0));
                }
                else {
                    res += helper(s, k, pos + 1, 0, (rem * 10 + i) % k, odd + i % 2, even + ((i % 2 == 0) && (!zero || i != 0)), zero & (i == 0));
                }
            }
        }
        else {
            for (int i = 0; i <= 9; i++)
            {
                res += helper(s, k, pos + 1, 0, (rem * 10 + i) % k, odd + i % 2, even + ((i % 2 == 0) && (!zero || i != 0)), zero & (i == 0));
            }
        }
        return dp[pos][tight][rem][odd][even][zero] = res;
    }

    int numberOfBeautifulIntegers(int low, int high, int k) {
        string a = to_string(low - 1);
        memset(dp, -1, sizeof(dp));
        int res1 = helper(a, k);
        string b = to_string(high);
        memset(dp, -1, sizeof(dp));
        int res2 = helper(b, k);
        return res2 - res1;
    }
};