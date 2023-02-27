class Solution {
public:
    void helper(int target, int i, vector<int>& candidates, vector<int> v, vector<vector<int>> &res){
        if(target <= 0 || i == candidates.size()){
            if(!target) res.push_back(v);
            return;
        }
        v.push_back(candidates[i]);
        helper(target - candidates[i], i, candidates, v, res);
        v.pop_back();
        helper(target, i+1, candidates, v, res);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        helper(target, 0, candidates, {}, res);
        return res;
    }
};