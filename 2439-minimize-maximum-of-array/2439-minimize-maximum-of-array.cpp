class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long res = nums[0], avg = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            avg += nums[i];
            res = max(res, (avg + i) / (i + 1));
        }
        return (int) res;
    }
};