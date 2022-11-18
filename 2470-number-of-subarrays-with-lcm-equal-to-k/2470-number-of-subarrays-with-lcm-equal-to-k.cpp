class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int n = nums.size(), res = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n && k%nums[j] == 0; j++)
            {
                nums[i] = lcm(nums[i], nums[j]);
                res += (nums[i] == k);
            }
        }
        return res;
    }
};