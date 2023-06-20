class Solution {
public:
    void helper(vector<int>& nums, int seen, vector<int> v, vector<vector<int>>& res){
        int n = nums.size();
        if(v.size() == n){
            res.push_back(v);
            return;
        }
        
        for (int i = 0; i < n; i++)
        {
            int bit = 1 << i;
            if(seen & bit) continue;
            v.push_back(nums[i]);
            helper(nums, seen | bit, v, res);
            v.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        helper(nums, 0, {}, res);
        return res;
    }
};