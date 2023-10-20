class Solution {
public:
    // pos, tight, found
    int dp[5][2][2];

    unordered_map<int, bool> mp1 = {{2, 1}, {5, 1}, {6, 1}, {9, 1}}; // good numbers
    unordered_map<int, bool> mp2 = {{3, 1}, {4, 1}, {7, 1}}; // invalid numbers

    int helper(string& s, int pos = 0, bool tight = 1, bool found = 0) {
        if(pos == s.size()) {
            return found;
        }
        if(dp[pos][tight][found] != -1) {
            return dp[pos][tight][found];
        }

        int res = 0, ub = tight ? s[pos] - '0' : 9;
        for (int i = 0; i <= ub; i++)
        {
            if(!mp2[i]) {
                res += helper(s, pos + 1, tight & (i == ub), found | mp1[i]);
            }
        }
        return dp[pos][tight][found] = res;
    }

    int rotatedDigits(int n) {
        string s = to_string(n);
        memset(dp, -1, sizeof(dp));
        return helper(s);
    }
};