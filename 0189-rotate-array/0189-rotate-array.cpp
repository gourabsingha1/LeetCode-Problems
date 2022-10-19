class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        k = nums.size() - k;
        vector<int> res;
        for (int i = k; i < nums.size(); i++)
        {
            res.push_back(nums[i]);
        }
        for (int i = 0; i < k; i++)
        {
            res.push_back(nums[i]);
        }
        nums = res;
        return;
    }
};