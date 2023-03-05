class Solution {
public:
    // space optimization
    int helper(int start, int end, vector<int>& nums) {
        int prev1 = nums[start], prev2 = 0;
        for (int i = start + 1; i < end; i++)
        {
            int take = nums[i] + prev2;
            int notTake = prev1;
            prev2 = prev1;
            prev1 = max(take, notTake); 
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1) {
            return nums[0];
        }
        int rob1 = helper(0, nums.size() - 1, nums); // exclude last house
        int rob2 = helper(1, nums.size(), nums); // exclude first house
        return max(rob1, rob2);
    }
};