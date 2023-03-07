class Solution {
public:
    // memoization
    bool helper(int currInd, string& s, unordered_map<string, bool>& dict, vector<int>& dp) {
        if(currInd == s.size()) {
            return 1;
        }
        if(dp[currInd] != -1) {
            return dp[currInd];
        }
        bool res = 0;
        for (int i = currInd; i < s.size(); i++)
        {
            if(dict[s.substr(currInd, i + 1 - currInd)]) {
                res |= helper(i + 1, s, dict, dp);
            }
        }
        return dp[currInd] = res;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, bool> dict;
        vector<int> dp(s.size(), -1);
        for(auto& s : wordDict) {
            dict[s] = 1;
        }
        return helper(0, s, dict, dp);
    }
};