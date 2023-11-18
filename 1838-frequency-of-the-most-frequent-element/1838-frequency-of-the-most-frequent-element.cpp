// optimal way is to sort the array first to find the max element
// from j to i, make all elements equal to nums[i]
// if it requires more than k operations, shrink the window

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int res = 0, n = nums.size();
        long sum = 0;
        for (int i = 0, j = 0; i < n; i++)
        {
            sum += nums[i];
            while(1LL * nums[i] * (i - j + 1) - sum > k) {
                sum -= nums[j++];
            }
            res = max(res, i - j + 1);
        }
        return res;
    }
};