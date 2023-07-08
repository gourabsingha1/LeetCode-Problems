class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> res, prev, cur;
        for(auto& x : arr) {
            cur = {x};
            for(auto& y : prev) {
                cur.insert(y | x);
            }
            for(auto& y : cur) {
                res.insert(y);
            }
            prev = cur;
        }
        return res.size();
    }
};