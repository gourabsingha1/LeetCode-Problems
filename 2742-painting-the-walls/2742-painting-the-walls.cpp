// in time == n, all the walls will be painted
// pick painters such that their time covers all n walls with minimum cost
// cntTime >= cost.size()

class Solution {
public:
    int dp[500][500];

    int helper(int cntTime, int n, vector<int>& cost, vector<int>& time) {
        if(cntTime >= cost.size()) {
            return 0;
        }
        if(n < 0) {
            return 1e9;
        }
        if(dp[cntTime][n] != -1) {
            return dp[cntTime][n];
        }

        int take = cost[n] + helper(cntTime + time[n] + 1, n - 1, cost, time);
        int notTake = helper(cntTime, n - 1, cost, time);
        return dp[cntTime][n] = min(take, notTake);
    }

    int paintWalls(vector<int>& cost, vector<int>& time) {
        memset(dp, -1, sizeof(dp));
        return helper(0, cost.size() - 1, cost, time);
    }
};