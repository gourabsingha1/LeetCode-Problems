class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), res = 0;
        vector<int> LIS(n);
        for (int i = n - 1; i >= 0; i--)
        {
            LIS[i] = 1;
            for (int j = i + 1; j < n; j++)
            {
                if(nums[i] < nums[j]){
                    LIS[i] = max(LIS[i], 1 + LIS[j]);
                }
            }
            res = max(res, LIS[i]);
        }
        return res;
    }
};