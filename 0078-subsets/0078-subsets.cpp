class Solution {
public:
    void helper(int currInd, vector<int>& nums, vector<int> v, vector<vector<int>> &res){
        int n = nums.size();
        if(currInd == n){
            res.push_back(v);
            return;
        }
        v.push_back(nums[currInd]);
        helper(currInd + 1, nums, v, res);
        v.pop_back();
        helper(currInd + 1, nums, v, res);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        helper(0, nums, {}, res);
        return res;
    }
};