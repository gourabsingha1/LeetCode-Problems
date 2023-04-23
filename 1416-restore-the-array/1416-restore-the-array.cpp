class Solution {
public:
    int M = 1e9 + 7;
    int helper(int i, string& s, int k, vector<int>& dp) {
        if(i == s.size()) {
            return 1;
        }
        if(s[i] == '0') {
            return 0;
        }
        if(dp[i] != -1) {
            return dp[i];
        }
        long take = 0, cur = 0;
        for (int j = i; j < s.size(); j++)
        {
            cur = cur * 10 + s[j] - '0';
            if(cur > k) {
                break;
            }
            take = (take + helper(j + 1, s, k, dp)) % M;
        }
        return dp[i] = take;
    }
    int numberOfArrays(string s, int k) {
        vector<int> dp(s.size(), -1);
        return helper(0, s, k, dp);
    }
};