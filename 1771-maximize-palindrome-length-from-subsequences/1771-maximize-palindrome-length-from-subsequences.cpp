// res should have characters from both words

class Solution {
public:
    int ans = 0;

    int helper(int i, int n, string& s, int boundary, vector<vector<int>>& dp) {
        if(i > n) {
            return 0;
        }
        if(i == n) {
            return 1;
        }
        if(dp[i][n] != -1) {
            return dp[i][n];
        }

        int res = 0;
        if(s[i] == s[n]) {
            res = 2 + helper(i + 1, n - 1, s, boundary, dp);
            // both characters inclusion check
            if(i < boundary && n >= boundary) {
                ans = max(ans, res);
            }
        }
        else {
            int first = helper(i + 1, n, s, boundary, dp);
            int second = helper(i, n - 1, s, boundary, dp);
            res = max(first, second);
        }
        return dp[i][n] = res;
    }
    
    int longestPalindrome(string word1, string word2) {
        string s = word1 + word2;
        int n = s.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        helper(0, n - 1, s, word1.size(), dp);
        return ans;
    }
};