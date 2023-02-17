class Solution {
public:
    vector<int> res;
    void helper(int curr, int n, int k){
        if(n == 1){
            res.push_back(curr);
            return;
        }
        for (int i = 0; i < 10; i++)
        {
            if(abs(curr % 10 - i) == k){
                helper(curr * 10 + i, n - 1, k);
            }
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        for (int i = 1; i < 10; i++)
        {
            helper(i, n, k);
        }
        return res;
    }
};