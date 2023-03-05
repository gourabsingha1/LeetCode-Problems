class Solution {
public:
    int rob(vector<int>& nums) {
        int prev1 = nums[0], prev2 = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            int take = nums[i] + prev2;
            int notTake = prev1;
            prev2 = prev1;
            prev1 = max(take, notTake);
        }
        return prev1;
    }
};