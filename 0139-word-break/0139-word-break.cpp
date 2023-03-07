class Solution {
public:
    // tabulation
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_map<string, bool> dict;
        vector<int> dp(n + 1, 0);
        for(auto& s : wordDict) {
            dict[s] = 1;
        }
        dp[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if(dp[j] && dict[s.substr(j, i - j)]) {
                    dp[i] = 1;
                    break;
                }
            }
        }
        return dp[n];
    }
};