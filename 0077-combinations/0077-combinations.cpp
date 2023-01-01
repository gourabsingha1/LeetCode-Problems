class Solution {
public:
    void helper(int k, int n, int currInd, vector<int> v, vector<vector<int>> &res){
        if(v.size() == k){
            res.push_back(v);
            return;
        }
        for (int i = currInd; i <= n; i++)
        {
            v.push_back(i);
            helper(k, n, i+1, v, res);
            v.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        helper(k, n, 1, {}, res);
        return res;
    }
};