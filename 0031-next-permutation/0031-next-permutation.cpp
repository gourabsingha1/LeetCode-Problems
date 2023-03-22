class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 1, j = i;
        while(i - 1 >= 0 && nums[i - 1] >= nums[i]) i--;
        i--;
        if(i >= 0) {
            while(nums[i] >= nums[j]) j--;
            swap(nums[i], nums[j]);
        }
        sort(nums.begin() + i + 1, nums.end());
    }
};