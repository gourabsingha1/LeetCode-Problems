// nums[i] = last element, nums[j] = second last element
// store the count of prev elements in the map of {current element index, diff}
// to get the longest subsequence in O(1)

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size(), res = 1;
        unordered_map<int, int> dp[n];
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                int diff = nums[i] - nums[j];
                int tempRes = 1 + dp[j][diff];
                dp[i][diff] = tempRes;
                res = max(res, dp[i][diff]);
            }
        }
        return res + 1;
    }
};