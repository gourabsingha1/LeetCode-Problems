class Solution {
public:
    // memoization
    unordered_map<string, int> dp;
    int helper(int n, vector<int>& nums, int target) {
        if(n < 0) {
            return !target;
        }
        string memo = to_string(n) + "*" + to_string(target);
        if(dp.find(memo) != dp.end()) {
            return dp[memo];
        }

        int neg = helper(n - 1, nums, target - nums[n]);
        int pos = helper(n - 1, nums, target + nums[n]);
        return dp[memo] = neg + pos;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return helper(nums.size() - 1, nums, target);
    }
};