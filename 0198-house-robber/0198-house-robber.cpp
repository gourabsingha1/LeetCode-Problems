class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() < 3){
            return *max_element(nums.begin(), nums.end());
        }
        nums[2] += nums[0];
        int res = max(nums[1], nums[2]);
        for (int i = 3; i < nums.size(); i++)
        {
            nums[i] += max(nums[i-2], nums[i-3]);
            res = max(res, nums[i]);
        }
        return res;
    }
};