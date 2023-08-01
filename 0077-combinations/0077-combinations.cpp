class Solution {
public:
    void helper(int currInd, vector<int> v, vector<vector<int>> &res, int& n, int& k){
        if(v.size() == k){
            res.push_back(v);
            return;
        }
        for (int i = currInd; i <= n; i++)
        {
            v.push_back(i);
            helper(i + 1, v, res, n, k);
            v.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        helper(1, {}, res, n, k);
        return res;
    }
};