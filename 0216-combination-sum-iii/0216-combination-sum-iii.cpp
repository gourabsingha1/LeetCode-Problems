class Solution {
public:
    void helper(int k, int n, int currInd, vector<int> v, vector<vector<int>> &res){
        if(n <= 0 || v.size() >= k){
            if(!n && v.size() == k) res.push_back(v);
            return;
        }
        for (int i = currInd; i <= 9; i++)
        {
            v.push_back(i);
            n -= i;
            helper(k, n, i+1, v, res);
            v.pop_back();
            n += i;
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        helper(k, n, 1, {}, res);
        return res;
    }
};