class Solution {
public:
    int dp[25][100];

    int helper(int rem, int i, string& num) {
        if(i == num.size()) {
            if(rem == 0) {
                return 0;
            }
            return 1e3;
        }
        if(dp[rem][i] != -1) {
            return dp[rem][i];
        }

        int take = helper((rem * 10 + num[i] - '0') % 25, i + 1, num);
        int notTake = 1 + helper(rem, i + 1, num);
        return dp[rem][i] = min(take, notTake);
    }

    int minimumOperations(string num) {
        memset(dp, -1, sizeof(dp));
        return helper(0, 0, num);
    }
};