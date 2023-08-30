class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long res = 0;
        int n = nums.size(), mi = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            int times = (nums[i] + mi - 1) / mi;
            res += times - 1;
            mi = nums[i] / times;
        }
        return res;
    }
};