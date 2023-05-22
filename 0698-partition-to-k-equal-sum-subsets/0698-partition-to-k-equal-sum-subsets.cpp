class Solution {
public:
    bool helper(int curInd, int cur, int& target, vector<bool>& vis, vector<int>& nums, int k) {
        if(k == 1) {
            return 1;
        }
        if(curInd == nums.size()) {
           return 0;
        }
        if(cur == target) {
            return helper(0, 0, target, vis, nums, k - 1);
        }
        bool res = 0;
        for (int i = curInd; i < nums.size(); i++)
        {
            if(vis[i] || cur + nums[i] > target) continue;
            vis[i] = 1;
            res |= helper(i + 1, cur + nums[i], target, vis, nums, k);
            if(res) return res;
            vis[i] = 0;
        }
        return res;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0), target = sum / k;
        if(sum % k) {
            return 0;
        }
        sort(nums.rbegin(), nums.rend());
        vector<bool> vis(nums.size(), 0);
        return helper(0, 0, target, vis, nums, k);
    }
};