class Solution {
public:
    // memoization
    long long helper(int i, vector<vector<int>>& questions, vector<long long>& dp) {
        if(i >= questions.size()) {
            return 0;
        }
        if(dp[i] != -1) {
            return dp[i];
        }
        long long take = questions[i][0] + helper(i + 1 + questions[i][1], questions, dp);
        long long notTake = helper(i + 1, questions, dp);
        return dp[i] = max(take, notTake);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> dp(questions.size(), -1);
        return helper(0, questions, dp);
    }
};