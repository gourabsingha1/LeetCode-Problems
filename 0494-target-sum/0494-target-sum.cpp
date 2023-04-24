class Solution {
public:
    int helper(int n, int cur, vector<int>& nums, int target) {
        if(n < 0) {
            return cur == target;
        }
        int neg = helper(n - 1, cur - nums[n], nums, target);
        int pos = helper(n - 1, cur + nums[n], nums, target);
        return neg + pos;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return helper(nums.size() - 1, 0, nums, target);
    }
};