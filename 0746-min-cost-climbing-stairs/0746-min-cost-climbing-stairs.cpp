class Solution {
public:
    int dp[1001];
    
    int helper(int i, vector<int>& cost) {
        if(i >= cost.size()) {
            return 0;
        }
        if(dp[i] != -1) {
            return dp[i];
        }

        int take1 = cost[i] + helper(i + 1, cost);
        int take2 = cost[i] + helper(i + 2, cost);
        return dp[i] = min(take1, take2);
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp, -1, sizeof(dp));
        int res1 = helper(0, cost);
        memset(dp, -1, sizeof(dp));
        int res2 = helper(1, cost);
        return min(res1, res2);
    }
};