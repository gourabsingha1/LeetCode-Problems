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
        while(currInd < n-1 && nums[currInd] == nums[currInd+1]) currInd++;
        helper(currInd + 1, nums, v, res);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        helper(0, nums, {}, res);
        return res;
    }
};