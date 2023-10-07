class Solution {
public:
    int M = 1e9 + 7;
    int dp[102][51][51];

    int helper(int mx, int i, int& n, int& m, int k) {
        if(k < 0) {
            return 0;
        }
        if(i == n) {
            return k == 0;
        }
        if(dp[mx + 1][i][k] != -1) {
            return dp[mx + 1][i][k];
        }

        int searchCost = 0;
        for (int j = 1; j <= m; j++)
        {
            // new maximum i.e searchCost++
            if(j > mx) {
                searchCost = (searchCost + helper(j, i + 1, n, m, k - 1)) % M;
            }
            else {
                searchCost = (searchCost + helper(mx, i + 1, n, m, k)) % M;
            }
        }
        return dp[mx + 1][i][k] = searchCost;
    }

    int numOfArrays(int n, int m, int k) {
        memset(dp, -1, sizeof(dp));
        return helper(-1, 0, n, m, k);
    }
};