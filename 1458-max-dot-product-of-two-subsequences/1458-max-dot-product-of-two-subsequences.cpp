class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size(), res = 0;
        int dp[n + 1][m + 1];
        for (int i = 0; i < n + 1; i++) dp[i][0] = -1e9;
        for (int i = 0; i < m + 1; i++) dp[0][i] = -1e9;
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < m + 1; j++)
            {
                dp[i][j] = max({nums1[i - 1] * nums2[j - 1], dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] + nums1[i - 1] * nums2[j - 1]});
            }
        }
        return dp[n][m];
    }
};