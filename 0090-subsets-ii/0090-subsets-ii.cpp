class Solution {
public:
    void helper(int currInd, vector<int>& nums, vector<int> v, vector<vector<int>> &res){
        int n = nums.size();
        res.push_back(v);
        for (int i = currInd; i < n; i++)
        {
            if(i != currInd && nums[i-1] == nums[i]) continue;
            v.push_back(nums[i]);
            helper(i + 1, nums, v, res);
            v.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        helper(0, nums, {}, res);
        return res;
    }
};