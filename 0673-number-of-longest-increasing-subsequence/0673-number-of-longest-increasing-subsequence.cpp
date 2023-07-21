class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size(), res = 0, lengthOfLIS = 1;
        vector<int> dp(n, 1), cnt(n, 1);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if(nums[j] < nums[i]){
                    if(dp[i] == 1 + dp[j]) {
                        cnt[i] += cnt[j];
                    }
                    else if(dp[i] < 1 + dp[j]) {
                        cnt[i] = cnt[j];
                    }
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
            lengthOfLIS = max(lengthOfLIS, dp[i]);
        }
        for (int i = 0; i < n; i++)
        {
            if(dp[i] == lengthOfLIS) {
                res += cnt[i];
            }
        }
        return res;
    }
};