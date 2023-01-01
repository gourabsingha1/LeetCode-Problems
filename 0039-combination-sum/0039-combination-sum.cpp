class Solution {
public:
    void helper(int target, int i, vector<int>& candidates, vector<int> v, vector<vector<int>> &res){
        if(target <= 0){
            if(!target){
                res.push_back(v);
            }
            return;
        }
        v.push_back(candidates[i]);
        target -= candidates[i];
        helper(target, i, candidates, v, res);
        v.pop_back();
        target += candidates[i];
        if(i < candidates.size() - 1){
            helper(target, i+1, candidates, v, res);
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        helper(target, 0, candidates, {}, res);
        return res;
    }
};