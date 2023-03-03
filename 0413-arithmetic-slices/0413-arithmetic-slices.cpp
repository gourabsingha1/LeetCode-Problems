class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int i = 1, n = nums.size(), res = 0;
        while(i < n) {
            int diff = nums[i] - nums[i - 1], curr = 0;
            i++;
            while(i < n && diff == nums[i] - nums[i - 1]) {
                curr++, i++;
            }
            res += curr * (curr + 1) / 2;
        }
        return res;
    }
};