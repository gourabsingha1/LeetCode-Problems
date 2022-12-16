class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        if(!nums.size()) return {{}};
        int first = nums[0];
        vector<int> rest = {nums.begin()+1, nums.end()};
        vector<vector<int>> temp = subsets(rest);
        vector<vector<int>> res;
        for(auto &t : temp){
            res.push_back(t);
            vector<int> add = t; add.push_back(first);
            res.push_back(add);
        }
        return res;
    }
};