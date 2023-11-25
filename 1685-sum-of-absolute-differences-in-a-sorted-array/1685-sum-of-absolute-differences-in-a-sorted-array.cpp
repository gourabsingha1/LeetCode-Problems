// for each nums[i]
// result[i] = (nums[i] * i - pre[i - 1]) + (suf[i + 1] - nums[i] * (n - i - 1))

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        vector<int> res;
        int n = nums.size(), pre = 0, suf = accumulate(nums.begin(), nums.end(), 0);
        for (int i = 0; i < n; i++)
        {
            suf -= nums[i];
            int leftSum = nums[i] * i - pre, rightSum = suf - nums[i] * (n - i - 1);
            res.push_back(leftSum + rightSum);
            pre += nums[i];
        }
        return res;
    }
};