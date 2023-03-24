class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int dp1 = cost[0], dp2 = cost[1];
        for (int i = 2; i < cost.size(); i++)
        {
            int temp = dp2;
            dp2 = min(dp2, dp1) + cost[i];
            dp1 = temp;
        }
        return min(dp1, dp2);
    }
};