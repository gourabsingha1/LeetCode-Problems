class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int isInc = 1, isDec = 1, n = nums.size();
        for (int i = 1; i < n; i++)
        {
            // check monotone increasing
            if(nums[i] < nums[i - 1]) {
                isInc = 0;
            }
            // check monotone decreasing
            if(nums[n - 1 - i] < nums[n - i]) {
                isDec = 0;
            }
        }
        return isInc | isDec;
    }
};