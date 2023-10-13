class Solution {
public:
    int dp[1002];
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        for (int i = n - 1; i >= 0; i--)
        {
            int take1 = cost[i] + dp[i + 1];
            int take2 = cost[i] + dp[i + 2];
            dp[i] = min(take1, take2);
        }
        return min(dp[0], dp[1]);
    }
};