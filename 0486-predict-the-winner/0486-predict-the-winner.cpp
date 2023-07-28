class Solution {
public:
    int helper(int i, int j, vector<int>& nums) {
        if(i > j) {
            return 0;
        }

        int takeLeft = nums[i] + min(helper(i + 2, j, nums), helper(i + 1, j - 1, nums));
        int takeRight = nums[j] + min(helper(i, j - 2, nums), helper(i + 1, j - 1, nums));
        return max(takeLeft, takeRight);
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int sumPlayer1 = helper(0, nums.size() - 1, nums);
        return sumPlayer1 >= (sum + 1) / 2;
    }
};