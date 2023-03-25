class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int res1 = 1, res2 = 1, inc1 = 0, inc2 = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if(nums[i] - nums[i - 1] > 0 && !inc1 || nums[i] - nums[i - 1] < 0 && inc1) {
                res1++;
                inc1 = !inc1;
            }
            if(nums[i] - nums[i - 1] > 0 && inc2 || nums[i] - nums[i - 1] < 0 && !inc2) {
                res2++;
                inc2 = !inc2;
            }
        }
        return max(res1, res2);
    }
};