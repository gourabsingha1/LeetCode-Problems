class Solution {
public:
    void helper(int target, int i, vector<int>& candidates, vector<int> v, vector<vector<int>> &res){
        if(target <= 0 || i == candidates.size()){
            if(!target) res.push_back(v);
            return;
        }
        v.push_back(candidates[i]);
        helper(target - candidates[i], i+1, candidates, v, res);
        v.pop_back();
        while(i < candidates.size()-1 && candidates[i] == candidates[i+1]){
            i++;
        }
        helper(target, i+1, candidates, v, res);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        helper(target, 0, candidates, {}, res);
        return res;
    }
};