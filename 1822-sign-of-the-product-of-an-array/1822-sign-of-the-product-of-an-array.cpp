class Solution {
public:
    int arraySign(vector<int>& nums) {
        int neg = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 0) return 0;
            if(nums[i] < 0) neg = -neg;
        }
        return neg;
    }
};