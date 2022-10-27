class Solution {
public:
    int minDifference(vector<int>& nums) {
        int res = 0, n = nums.size();
        if(n < 5){
            return 0;
        }
        sort(nums.begin(), nums.end());
        res = min({nums[n-4]-nums[0], nums[n-3]-nums[1], nums[n-2]-nums[2], nums[n-1]-nums[3]});
        return res;
    }
};