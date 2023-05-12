class Solution {
public:
    // tabulation
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            long long take = questions[i][0] + dp[min(i + 1 + questions[i][1], n)];
            long long notTake = dp[i + 1];
            dp[i] = max(take, notTake);
        }
        return dp[0];
    }
};