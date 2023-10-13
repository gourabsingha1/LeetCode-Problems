class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size(), dp1 = 0, dp2 = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            int take1 = cost[i] + dp1;
            int take2 = cost[i] + dp2;
            int dp = min(take1, take2);
            dp2 = dp1;
            dp1 = dp;
        }
        return min(dp1, dp2);
    }
};