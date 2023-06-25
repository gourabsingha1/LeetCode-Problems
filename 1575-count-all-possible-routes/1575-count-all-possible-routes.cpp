class Solution {
public:
    int M = 1e9 + 7;
    int helper(int i, vector<int>& locations, int& finish, int fuel, vector<vector<int>>& dp) {
        if(fuel < 0) {
            return 0;
        }
        if(dp[i][fuel] != -1) {
            return dp[i][fuel];
        }

        int res = i == finish;
        for (int j = 0; j < locations.size(); j++)
        {
            if(i == j) continue;
            int x = abs(locations[i] - locations[j]);
            res = (res + helper(j, locations, finish, fuel - x, dp)) % M;
        }
        return dp[i][fuel] = res;
    }

    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        vector<vector<int>> dp(locations.size(), vector<int> (fuel + 1, -1));
        return helper(start, locations, finish, fuel, dp);
    }
};