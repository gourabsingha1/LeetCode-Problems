class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0, prev = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if(nums[i] <= prev){
                res += prev - nums[i] + 1;
                prev++;
            }
            else{
                prev = nums[i];
            }
        }
        return res;
    }
};