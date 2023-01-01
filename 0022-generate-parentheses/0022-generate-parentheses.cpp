class Solution {
public:
    void helper(int i, int n, int left, int right, string s, vector<string> &res){
        if(left < right || left > n/2 || right > n/2){
            return;
        }
        if(i == n){
            res.push_back(s);
            return;
        }
        helper(i+1, n, left + 1, right, s + "(", res);
        helper(i+1, n, left, right + 1, s + ")", res);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        helper(0, 2*n, 0, 0, "", res);
        return res;
    }
};