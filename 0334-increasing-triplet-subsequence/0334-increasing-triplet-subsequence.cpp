class Solution {
public:
    int LIS(vector<int>& nums) {
        vector<int> LIS = {nums[0]};
        for (int i = 1; i < nums.size(); i++)
        {
            int lb = lower_bound(LIS.begin(), LIS.end(), nums[i]) - LIS.begin();
            if(lb == LIS.size()) {
                LIS.push_back(nums[i]);
            }
            else {
                LIS[lb] = nums[i];
            }
        }
        return LIS.size();
    }
    bool increasingTriplet(vector<int>& nums) {
        return LIS(nums) >= 3;
    }
};