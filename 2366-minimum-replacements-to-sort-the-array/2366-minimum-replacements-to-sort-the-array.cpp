class Solution {
public:
    int lowerbound(int high, int times, int target) {
        int low = 1;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(mid * times == target) {
                return mid;
            }
            else if(mid * times < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return high;
    }

    long long minimumReplacement(vector<int>& nums) {
        long long res = 0;
        int n = nums.size(), mi = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            res += (nums[i] - 1) / mi;
            int times = (nums[i] + mi - 1) / mi;
            mi = max(1, lowerbound(mi, times, nums[i]));
        }
        return res;
    }
};