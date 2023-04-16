class Solution {
public:
    // memoization
    int M = 1e9 + 7;
    int helper(int w, int t, vector<string>& words, string& target, vector<vector<int>>& dp) {
        if(t < 0) {
            return 1;
        }
        else if(w < t) {
            return 0;
        }
        else if(dp[w][t] != -1) {
            return dp[w][t];
        }

        long take = 0;
        for (int i = 0; i < words.size(); i++)
        {
            if(words[i][w] == target[t]) {
                take = (take + helper(w - 1, t - 1, words, target, dp)) % M;
            }
        }
        int notTake = helper(w - 1, t, words, target, dp) % M;
        return dp[w][t] = (take + notTake) % M;
    }
    int numWays(vector<string>& words, string target) {
        int w = words[0].size(), t = target.size();
        vector<vector<int>> dp(w, vector<int> (t, -1));
        return helper(w - 1, t - 1, words, target, dp);
    }
};