class Solution {
public:
    void helper(vector<int>& nums, vector<int>& seen, vector<int> v, vector<vector<int>>& res){
        int n = nums.size();
        if(v.size() == n){
            res.push_back(v);
            return;
        }
        
        for (int i = 0; i < n; i++)
        {
            if(seen[i]) continue;
            v.push_back(nums[i]);
            seen[i] = 1;
            helper(nums, seen, v, res);
            v.pop_back();
            seen[i] = 0;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> seen(nums.size());
        helper(nums, seen, {}, res);
        return res;
    }
};