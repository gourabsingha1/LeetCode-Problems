class Solution{
public:
    void helper(int target, int currInd, vector<int>& candidates, vector<int> v, vector<vector<int>> &res){
        int n = candidates.size();
        if(target <= 0 || currInd == n){
            if(!target) res.push_back(v);
            return;
        }
        for (int i = currInd; i < n; i++)
        {
            v.push_back(candidates[i]);
            target -= candidates[i];
            helper(target, i, candidates, v, res);
            v.pop_back();
            target += candidates[i];
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        helper(target, 0, candidates, {}, res);
        return res;
    }
};