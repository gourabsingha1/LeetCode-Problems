// greedy choice is to pick leftmost and rightmost element

class Solution {
public:
    int dp[500][500];
    int helper(int i, int j, vector<int>& nums, int& x) {
        if(i > j) {
            return 0;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        int take1 = min(x, nums[j] - nums[i]) + helper(i + 1, j - 1, nums, x);
        int take2 = min(x, nums[i + 1] - nums[i]) + helper(i + 2, j, nums, x);
        int take3 = min(x, nums[j] - nums[j - 1]) + helper(i, j - 2, nums, x);
        return dp[i][j] = min({take1, take2, take3});
    }

    int minOperations(string s1, string s2, int x) {
        int n = s1.size();
        vector<int> nums;
        for (int i = 0; i < n; i++)
        {
            if(s1[i] != s2[i]) {
                nums.push_back(i);
            }
        }
        if(nums.size() & 1) {
            return -1;
        }

        memset(dp, -1, sizeof(dp));
        return helper(0, nums.size() - 1, nums, x);
    }
};