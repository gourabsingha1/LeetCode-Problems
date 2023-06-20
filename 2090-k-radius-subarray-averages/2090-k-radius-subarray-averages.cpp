class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        long n = nums.size(), sum = 0;
        vector<int> res(n, -1);
        for (int i = 0, j = 0; i < n; i++)
        {
            sum += nums[i];
            if(i >= 2 * k) {
                res[i - k] = sum / (2 * k + 1);
                sum -= nums[j++];
            }
        }
        return res;
    }
};