class Solution {
public:
    void helper(int n, unordered_map<int, int> &m, vector<int> v, vector<vector<int>> &res){
        if(v.size() == n){
            res.push_back(v);
            return;
        }
        for(auto &[x, y] : m){
            if(!y) continue;
            v.push_back(x);
            y--;
            helper(n, m, v, res);
            v.pop_back();
            y++;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        unordered_map<int, int> m;
        for(auto &x : nums) m[x]++;
        helper(nums.size(), m, {}, res);
        return res;
    }
};