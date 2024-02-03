// from the nth index find max element for every range from 1 to K (K goes from 1 to k)
// set that max element and the number of times it was chosen
// then move on

class Solution {
public:
    int dp[501];

    int helper(int n, vector<int>& nums, int& k) {
        if(n < 0) {
            return 0;
        }
        if(dp[n] != -1) {
            return dp[n];
        }
        
        int mx = nums[n], res = 0, K = 0;
        while(n - K >= 0 && K < k) {
            mx = max(mx, nums[n - K]);
            res = max(res, mx * (++K) + helper(n - K, nums, k));
        }
        return dp[n] = res;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        memset(dp, -1, sizeof(dp));
        return helper(n - 1, arr, k);
    }
};