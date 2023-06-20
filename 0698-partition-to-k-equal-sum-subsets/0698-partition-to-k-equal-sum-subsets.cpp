// bitmask

class Solution {
public:
    bool helper(int curInd, int cur, int& target, int seen, vector<int>& nums, int k, vector<vector<int>>& dp) {
        if(k == 1) {
            return 1;
        }
        if(curInd == nums.size()) {
           return 0;
        }
        if(cur == target) {
            return helper(0, 0, target, seen, nums, k - 1, dp);
        }
        if(dp[curInd][seen] != -1) {
            return dp[curInd][seen];
        }
        
        bool res = 0;
        for (int i = curInd; i < nums.size(); i++)
        {
            int bit = 1 << i;
            if(seen & bit || cur + nums[i] > target) continue;
            res |= helper(i + 1, cur + nums[i], target, seen | bit, nums, k, dp);
            if(res) break;
        }
        return dp[curInd][seen] = res;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0), target = sum / k;
        if(sum % k) {
            return 0;
        }
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int> (1 << n, -1));
        return helper(0, 0, target, 0, nums, k, dp);
    }
};