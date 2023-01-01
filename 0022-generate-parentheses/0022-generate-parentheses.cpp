class Solution {
public:
    void helper(int n, int left, int right, string s, vector<string> &res){
        if(left < right || left > n/2 || right > n/2){
            return;
        }
        if(left + right == n){
            res.push_back(s);
            return;
        }
        helper(n, left + 1, right, s + "(", res);
        helper(n, left, right + 1, s + ")", res);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        helper(2*n, 0, 0, "", res);
        return res;
    }
};