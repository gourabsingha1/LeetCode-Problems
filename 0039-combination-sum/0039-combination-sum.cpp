class Solution {
public:
    void helper(int curr, int target, int i, vector<int>& candidates, vector<int> v, vector<vector<int>> &res){
        int n = candidates.size();
        if(i >= n || curr > target){
            if(curr == target){
                res.push_back(v);
            }
            return;
        }
        v.push_back(candidates[i]);
        curr += candidates[i];
        helper(curr, target, i, candidates, v, res);
        v.pop_back();
        curr -= candidates[i];
        helper(curr, target, i+1, candidates, v, res);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        helper(0, target, 0, candidates, {}, res);
        return res;
    }
};