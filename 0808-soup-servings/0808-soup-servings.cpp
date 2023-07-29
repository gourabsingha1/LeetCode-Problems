class Solution {
public:
    vector<pair<int, int>> operations = {{100, 0}, {75, 25}, {50, 50}, {25, 75}};
    
    double helper(int soupA, int soupB, vector<vector<double>>& dp) {
        if(soupA <= 0 && soupB <= 0) {
            return 0.5;
        }
        if(soupB <= 0) {
            return 0;
        }
        if(soupA <= 0) {
            return 1;
        }
        if(dp[soupA][soupB] != -1) {
            return dp[soupA][soupB];
        }

        double res = 0;
        for (int i = 0; i < 4; i++)
        {
            int dx = soupA - operations[i].first, dy = soupB - operations[i].second;
            res += 0.25 * helper(dx, dy, dp);
        }
        return dp[soupA][soupB] = res;
    }

    double soupServings(int n) {
        if(n > 4800) return 1;
        vector<vector<double>> dp(n + 1, vector<double> (n + 1, -1));
        return helper(n, n, dp);
    }
};