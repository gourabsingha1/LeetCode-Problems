class Solution {
public:
    vector<string> res;
    unordered_map<string, bool> seen;
    void helper(int right, string cur, int n, string& s) {
        if(n < 0) {
            if(!right && (res.size() == 0 || res.back().size() == cur.size() && !seen[cur])) {
                res.push_back(cur);
                seen[cur] = 1;
            }
            return;
        }

        if(isalpha(s[n])) {
            helper(right, s[n] + cur, n - 1, s); // take
            return;
        }
        
        if(s[n] == ')') {
            helper(right + 1, s[n] + cur, n - 1, s); // take
        }
        else if(right > 0) {
            helper(right - 1, s[n] + cur, n - 1, s); // take
        }
        helper(right, cur, n - 1, s); // notTake
    }

    vector<string> removeInvalidParentheses(string s) {
        helper(0, "", s.size() - 1, s);
        if(res.size() == 0) return {""};
        return res;
    }
};