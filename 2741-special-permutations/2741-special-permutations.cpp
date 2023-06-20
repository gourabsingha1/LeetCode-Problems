// mask = vis array = eg:- 0000000010001 (binary of 17) = 0th and 4th elements are consumed

class Solution {
public:
    int M = 1e9 + 7;
    int helper(int i, int ind, vector<int>& nums, vector<vector<int>>& dp, int mask){
        int n = nums.size();
        if(ind == n){
            return 1;
        }
        if(dp[i][mask] != -1) {
            return dp[i][mask];
        }

        int res = 0;
        for (int j = 0; j < n; j++)
        {
            if(mask & (1 << j)) continue; // if vis[i] then continue
            if(mask == 0 || nums[i] % nums[j] == 0 || nums[j] % nums[i] == 0) {
                res = (res + helper(j, ind + 1, nums, dp, mask | (1 << j))) % M;
            }
        }
        return dp[i][mask] = res;
    }

    int specialPerm(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int> (1 << 14, -1));
        return helper(0, 0, nums, dp, 0);
    }
};