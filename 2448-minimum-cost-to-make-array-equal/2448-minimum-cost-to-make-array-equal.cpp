class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long res = LONG_LONG_MAX;
        int low = 1, high = 1e6;
        while(low <= high) {
            long long mid = high + (low - high) / 2, sum1 = 0, sum2 = 0;
            for (int i = 0; i < nums.size(); i++)
            {
                sum1 += 1LL * abs(nums[i] - mid) * cost[i];
                sum2 += 1LL * abs(nums[i] - mid + 1) * cost[i];
            }
            if(sum1 < sum2) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
            res = min({res, sum1, sum2});
        }
        return res;
    }
};