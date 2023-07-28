class Solution {
public:
    int helper(int i, int j, bool player1, vector<int>& nums) {
        if(i > j) {
            return 0;
        }

        int res = 0;
        if(player1) {
            int takeLeft = nums[i] + helper(i + 1, j, !player1, nums);
            int takeRight = nums[j] + helper(i, j - 1, !player1, nums);
            res = max(takeLeft, takeRight);
        }
        else {
            int takeLeft = -nums[i] + helper(i + 1, j, !player1, nums);
            int takeRight = -nums[j] + helper(i, j - 1, !player1, nums);
            res = min(takeLeft, takeRight);
        }
        return res;
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        return helper(0, nums.size() - 1, 1, nums) >= 0;
    }
};