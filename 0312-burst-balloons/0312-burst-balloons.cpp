// https://www.youtube.com/watch?v=Yz4LlDSlkns&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=70

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));
        for (int i = n - 2; i >= 1; i--)
        {
            for (int j = 1; j + 1 < n; j++)
            {
                if(i > j) continue;
                int res = INT_MIN;
                for (int k = i; k <= j; k++)
                {
                    int left = dp[i][k - 1];
                    int right = dp[k + 1][j];
                    int cost = nums[i - 1] * nums[k] * nums[j + 1] + left + right;
                    res = max(res, cost);
                }
                dp[i][j] = res;
            }
        }
        return dp[1][n - 2];
    }
};