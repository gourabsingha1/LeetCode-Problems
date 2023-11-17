class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int res = 0, i = 0, j = nums.size() - 1;
        sort(nums.begin(), nums.end());
        while(i < j) {
            res = max(res, nums[j--] + nums[i++]);
        }
        return res;
    }
};