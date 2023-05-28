class Solution {
public:
    int helper(int l, int r, vector<int>&cuts, vector<vector<int>>& dp) {
        if(l > r) {
            return 0;
        }
        if(dp[l][r] != -1) {
            return dp[l][r];
        }
        int res = INT_MAX;
        for (int i = l; i <= r; i++)
        {
            int cost = cuts[r + 1] - cuts[l - 1];
            int left = helper(l, i - 1, cuts, dp);
            int right = helper(i + 1, r, cuts, dp);
            res = min(res, cost + left + right);
        }
        return dp[l][r] = res;
    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        int size = cuts.size();
        vector<vector<int>> dp(size, vector<int> (size, -1));
        return helper(1, size - 2, cuts, dp);
    }
};