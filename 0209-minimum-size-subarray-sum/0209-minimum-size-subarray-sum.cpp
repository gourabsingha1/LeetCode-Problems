class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0, n = nums.size(), res = n + 1;
        for (int i = 0, j = 0; i < n; i++)
        {
            sum += nums[i];
            while(sum >= target) {
                int size = i - j + 1;
                res = min(res, size);
                sum -= nums[j++];
            }
        }
        if(res > n) {
            return 0;
        }
        return res;
    }
};