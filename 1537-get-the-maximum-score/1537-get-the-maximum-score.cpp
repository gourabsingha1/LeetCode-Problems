class Solution {
public:
    int M = 1e9 + 7;

    long helper(int n, bool isNums1, unordered_map<int, int>& mp1, unordered_map<int, int>& mp2, vector<int>& nums1, vector<int>& nums2, vector<vector<long>>& dp) {
        if(n < 0) {
            return 0;
        }
        if(dp[n][isNums1] != -1) {
            return dp[n][isNums1];
        }

        long one = 0, two = 0;
        if(isNums1) {
            one = nums1[n] + helper(n - 1, 1, mp1, mp2, nums1, nums2, dp);
            if(mp2.find(nums1[n]) != mp2.end()) {
                one = max(one, nums1[n] + helper(mp2[nums1[n]] - 1, 0, mp1, mp2, nums1, nums2, dp));
            }
        }
        else {
            two = nums2[n] + helper(n - 1, 0, mp1, mp2, nums1, nums2, dp);
            if(mp1.find(nums2[n]) != mp1.end()) {
                two = max(two, nums2[n] + helper(mp1[nums2[n]] - 1, 1, mp1, mp2, nums1, nums2, dp));
            }
        }
        return dp[n][isNums1] = max(one, two);
    }

    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        unordered_map<int, int> mp1, mp2;
        for (int i = 0; i < n; i++)
        {
            mp1[nums1[i]] = i;
        }
        for (int i = 0; i < m; i++)
        {
            mp2[nums2[i]] = i;
        }
        vector<vector<long>> dp1(n + m, vector<long> (2, -1)), dp2(n + m, vector<long> (2, -1));
        long one = helper(n - 1, 1, mp1, mp2, nums1, nums2, dp1);
        long two = helper(m - 1, 0, mp1, mp2, nums1, nums2, dp2);
        return max(one, two) % M;
    }
};