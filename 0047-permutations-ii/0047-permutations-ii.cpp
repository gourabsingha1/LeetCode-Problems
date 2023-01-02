class Solution {
public:
    void helper(int currInd, vector<int> nums, vector<vector<int>> &res){
        int n = nums.size();
        if(currInd == n){
            res.push_back(nums);
            return;
        }
        for (int i = currInd; i < n; i++)
        {
            if(i != currInd && nums[i] == nums[currInd]) continue;
            swap(nums[i], nums[currInd]);
            helper(currInd + 1, nums, res);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        helper(0, nums, res);
        return res;
    }
};