class Solution {
public:
    void helper(int target, int currInd, vector<int>& candidates, vector<int> v, vector<vector<int>> &res){
        int n = candidates.size();
        if(target <= 0){
            if(!target) res.push_back(v);
            return;
        }
        for (int i = currInd; i < n; i++)
        {
            if(i != currInd && candidates[i] == candidates[i-1]) continue;
            v.push_back(candidates[i]);
            target -= candidates[i];
            helper(target, i+1, candidates, v, res);
            v.pop_back();
            target += candidates[i];
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        helper(target, 0, candidates, {}, res);
        return res;
    }
};