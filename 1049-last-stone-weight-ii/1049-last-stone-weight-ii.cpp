// minimum difference bw sum of two subsets of array

class Solution {
public:
    int helper(int n, int left, int right, vector<int>& stones, vector<vector<int>>& dp) {
        int diff = abs(right - left);
        if(n < 0) {
            return diff;
        }
        if(dp[n][diff] != -1) {
            return dp[n][diff];
        }

        int diff1 = helper(n - 1, left + stones[n], right - stones[n], stones, dp);
        int diff2 = helper(n - 1, left, right, stones, dp);
        return dp[n][diff] = min(diff1, diff2);
    }

    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size(), m = accumulate(stones.begin(), stones.end(), 0);
        vector<vector<int>> dp(n, vector<int> (m + 1, -1));
        return helper(n - 1, 0, m, stones, dp);
    }
};