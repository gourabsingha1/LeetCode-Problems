// put k = 0, 1, 2 and find the formula
// F(1) = F(0) + sum - n * nums[n - 1]
// F(2) = F(1) + sum - n * nums[n - 2]
// space optimization

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size(), sum = 0, prev = 0, cur = 0;
        for (int i = 0; i < n; i++)
        {
            prev += i * nums[i];
            sum += nums[i];
        }
        int res = prev;
        for (int i = 1; i < n; i++)
        {
            cur = prev + sum - n * nums[n - i];
            res = max(res, cur);
            prev = cur;
        }
        return res;
    }
};