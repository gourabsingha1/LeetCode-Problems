// 3, 8, 3
// nums[i] = 8, mi = 3
// break 8 into 3 parts | (nums[i] + mi - 1) / mi = 3
// add (8 - 1) / 3 = 2 to res | (nums[i] - 1) / mi = 2
// low = 1, high = mi
// for every mid, check if mid + mid + mid ... >= target (nums[i]) | mid * times >= target
// i.e the lower_bound will be the current minimum (mi)

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
            mi = lowerbound(mi, times, nums[i]);
        }
        return res;
    }
};