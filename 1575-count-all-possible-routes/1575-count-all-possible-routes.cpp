class Solution {
public:
    int M = 1e9 + 7;
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();
        vector<vector<int>> dp(n, vector<int> (fuel + 1, 0));
        for (int f = 0; f <= fuel; f++)
        {
            for (int i = 0; i < n; i++)
            {
                int res = i == finish;
                for (int j = 0; j < n; j++)
                {
                    if(i == j) continue;
                    int x = abs(locations[i] - locations[j]);
                    if(f >= x) {
                        res = (res + dp[j][f - x]) % M;
                    }
                }
                dp[i][f] = res;
            }
        }
        return dp[start][fuel];
    }
};