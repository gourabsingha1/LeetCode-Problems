class Solution {
public:
    bool helper(int n, string& s, unordered_map<string, bool>& dict, vector<int>& dp) {
        if(n < 0) {
            return 1;
        }
        if(dp[n] != -1) {
            return dp[n];
        }
        
        bool res = 0;
        for (int i = n; i >= 0; i--)
        {
            if(dict[s.substr(i, n - i + 1)]) {
                res |= helper(i - 1, s, dict, dp);
            }
        }
        return dp[n] = res;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, bool> dict;
        vector<int> dp(s.size(), -1);
        for(auto& s : wordDict) {
            dict[s] = 1;
        }
        return helper(s.size() - 1, s, dict, dp);
    }
};