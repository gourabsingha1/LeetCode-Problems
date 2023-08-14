class Solution {
public:
    int dp[1000][1000], res = 0;
    
    int helper(int i, int j, vector<int>& nums1, vector<int>& nums2) {
        if(i < 0 || j < 0) {
            return 0;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        int take = 0;
        if(nums1[i] == nums2[j]) {
            take = 1 + helper(i - 1, j - 1, nums1, nums2);
        }
        int notTake1 = helper(i - 1, j, nums1, nums2);
        int notTake2 = helper(i, j - 1, nums1, nums2);
        res = max(res, take);
        return dp[i][j] = take;
    }
    
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        memset(dp, -1, sizeof(dp));
        helper(n - 1, m - 1, nums1, nums2);
        return res;
    }
};