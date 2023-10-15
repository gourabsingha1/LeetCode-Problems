// ind cannot be greater than steps
// because we need to travel count(steps) to reach ind
// hence we can reduce space

class Solution {
public:
    int M = 1e9 + 7;
    int helper(int ind, int steps, int& arrLen, vector<vector<int>>& dp) {
        if(steps == 0) {
            return ind == 0;
        }
        if(ind < 0 || ind == arrLen || ind > steps) {
            return 0;
        }
        if(dp[ind][steps] != -1) {
            return dp[ind][steps];
        }

        int stay = helper(ind, steps - 1, arrLen, dp);
        int left = helper(ind - 1, steps - 1, arrLen, dp);
        int right = helper(ind + 1, steps - 1, arrLen, dp);
        return dp[ind][steps] = ((stay + left) % M + right) % M;
    }
    int numWays(int steps, int arrLen) {
        vector<vector<int>> dp(steps, vector<int> (steps + 1, -1));
        return helper(0, steps, arrLen, dp);
    }
};