// brute force - O(n * k * target), O(n * target)

class Solution {
public:
    const int M = 1e9 + 7;
    int dp[31][1001];

    int helper(int n, int& k, int target) {
        if(n == 0) {
            return target == 0;
        }
        if(dp[n][target] != -1) {
            return dp[n][target];
        }

        int res = 0;
        for (int dk = 1; dk <= k; dk++)
        {
            if(target - dk >= 0) {
                res = (0LL + res + helper(n - 1, k, target - dk)) % M;
            }
            else {
                break;
            }
        }
        return dp[n][target] = res;
    }

    int numRollsToTarget(int n, int k, int target) {
        memset(dp, -1, sizeof(dp));
        return helper(n, k, target);
    }
};