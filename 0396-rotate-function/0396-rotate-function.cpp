// put k = 0, 1, 2 and find the formula
// F(1) = F(0) + sum - n * nums[n - 1]
// F(2) = F(1) + sum - n * nums[n - 2]

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        vector<int> F(n);
        for (int i = 0; i < n; i++)
        {
            F[0] += i * nums[i];
            sum += nums[i];
        }
        for (int i = 1; i < n; i++)
        {
            F[i] = F[i - 1] + sum - n * nums[n - i];
        }
        return *max_element(F.begin(), F.end());
    }
};