class Solution {
public:
    // pos, tight, seen, found
    int dp[10][2][1024][2];

    int helper(string& s, int pos = 0, bool tight = 1, int seen = 0, bool found = 0) {
        if(pos == s.size()) {
            return found;
        }
        if(dp[pos][tight][seen][found] != -1) {
            return dp[pos][tight][seen][found];
        }

        int res = 0, ub = tight ? s[pos] - '0' : 9;
        for (int i = 0; i <= ub; i++)
        {
            int mask = (1 << i);
            if(seen == 0 && i == 0) { // leading zero
                res += helper(s, pos + 1, tight & (i == ub), seen, found);
            }
            else {
                res += helper(s, pos + 1, tight & (i == ub), seen | mask, found | (seen & mask));
            }
        }
        return dp[pos][tight][seen][found] = res;
    }

    int numDupDigitsAtMostN(int n) {
        string s = to_string(n);
        memset(dp, -1, sizeof(dp));
        return helper(s);
    }
};