class Solution {
public:
    // memoization
    vector<int> pass = {1, 7, 30};
    int helper(int i, int costInd, vector<int>& days, vector<int>& costs, vector<vector<int>>& dp) {
        if(costInd == 3 || i == days.size()) {
            if(i < days.size()) {
                return 1e9;
            }
            return 0;
        }
        if(dp[i][costInd] != -1) {
            return dp[i][costInd];
        }
        int j = i;
        while(i < days.size() && days[i] < days[j] + pass[costInd]) {
            i++;
        }
        int take = costs[costInd] + helper(i, 0, days, costs, dp);
        int notTake = helper(j, costInd + 1, days, costs, dp);
        return dp[j][costInd] = min(take, notTake);
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<vector<int>> dp(days.size(), vector<int> (3, -1));
        return helper(0, 0, days, costs, dp);
    }
};