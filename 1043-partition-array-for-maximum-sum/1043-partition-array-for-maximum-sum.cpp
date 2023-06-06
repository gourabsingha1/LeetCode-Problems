class Solution {
public:
    int helper(int n, vector<int>& nums, int k, vector<int>& dp) {
        if(n < 0) {
            return 0;
        }
        if(dp[n] != -1) {
            return dp[n];
        }
        
        int ma = nums[n], res = 0;
        for (int i = n, cnt = 1; i >= max(0, n + 1 - k); i--, cnt++)
        {
            ma = max(ma, nums[i]);
            res = max(res, ma * cnt + helper(i - 1, nums, k, dp));
        }
        return dp[n] = res;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, -1);
        return helper(n - 1, arr, k, dp);
    }
};