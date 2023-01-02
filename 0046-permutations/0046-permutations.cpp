class Solution {
public:
    void helper(vector<int>& nums, unordered_map<int, int> &m, vector<int> v, vector<vector<int>> &res){
        int n = nums.size();
        if(v.size() == n){
            res.push_back(v);
            return;
        }
        for (int i = 0; i < n; i++)
        {
            if(m[i]) continue;
            v.push_back(nums[i]);
            m[i] = 1;
            helper(nums, m, v, res);
            v.pop_back();
            m[i] = 0;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        unordered_map<int, int> m;
        helper(nums, m, {}, res);
        return res;
    }
};