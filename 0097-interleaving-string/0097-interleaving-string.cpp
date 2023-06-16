class Solution {
public:
    unordered_map<string, bool> dp;
    bool helper(int n, int m, int o, string& s1, string& s2, string& s3) {
        if(o < 0) {
            return n < 0 && m < 0;
        }
        string memo = to_string(n) + "*" + to_string(m) + "*" + to_string(o);
        if(dp.find(memo) != dp.end()) {
            return dp[memo];
        }

        bool res = 0, flag = 0;
        if(n >= 0 && s1[n] == s3[o]) {
            res |= helper(n - 1, m, o - 1, s1, s2, s3);
            flag = 1;
        }
        if(m >= 0 && s2[m] == s3[o]) {
            res |= helper(n, m - 1, o - 1, s1, s2, s3);
            flag = 1;
        }
        return dp[memo] = res;
    }

    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(), m = s2.size(), o = s3.size();
        if(n + m != o) return 0;
        return helper(n - 1, m - 1, o - 1, s1, s2, s3);
    }
};