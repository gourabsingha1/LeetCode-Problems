class Solution {
public:
    bool canJump(vector<int>& nums) {
        int c = 0;
        for (int i = nums.size()-2; i >= 0; i--)
        {
            c++;
            if(nums[i] >= c) c = 0;
        }
        return !c;
    }
};