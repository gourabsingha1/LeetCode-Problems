class Solution {
public:
    // memoization
    int helper(int n, vector<int>& nums, int target, unordered_map<string, int>& dp) {
        if(n < 0) {
            return !target;
        }
        string memo = to_string(n) + "*" + to_string(target);
        if(dp.find(memo) != dp.end()) {
            return dp[memo];
        }

        int neg = neg = helper(n - 1, nums, target - nums[n], dp);
        int pos = helper(n - 1, nums, target + nums[n], dp);
        return dp[memo] = neg + pos;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<string, int> dp;
        return helper(nums.size() - 1, nums, target, dp);
    }
};