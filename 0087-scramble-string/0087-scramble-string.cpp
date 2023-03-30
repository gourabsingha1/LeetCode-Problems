class Solution {
public:
    unordered_map<string, bool> dp;
    bool isScramble(string s1, string s2) {
        if(s1 == s2) {
            return 1;
        }
        string s = s1 + s2;
        if(dp.find(s) != dp.end()) {
            return dp[s];
        }
        int n = s1.size();
        for (int i = 1; i < n; i++)
        {
            if(isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i)) || isScramble(s1.substr(0, i), s2.substr(n - i)) && isScramble(s1.substr(i), s2.substr(0, n - i))) {
                return dp[s] = 1;
            }
        }
        return dp[s] = 0;
    }
};