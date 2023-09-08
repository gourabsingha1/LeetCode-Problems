class Solution {
public:
    bool isPredecessor(string& word1, string& word2) {
        int i = 0, j = 0, cnt = 1;
        while(i < word1.size() && j < word2.size()) {
            if(word1[i] != word2[j]) {
                if(cnt == 1) {
                    i--, cnt = 0;
                }
                else {
                    return 0;
                }
            }
            i++, j++;
        }
        return 1;
    }

    int helper(int j, int i, vector<string>& words, vector<vector<int>>& dp) {
        if(i == words.size()) {
            return 0;
        }
        if(dp[i][j + 1] != -1) {
            return dp[i][j + 1];
        }

        int take = 0;
        if(j == -1) {
            take = 1 + helper(i, i + 1, words, dp);
        }
        else if(words[j].size() + 1 == words[i].size() && isPredecessor(words[j], words[i])) {
            take = 1 + helper(i, i + 1, words, dp);
        }
        int notTake = helper(j, i + 1, words, dp);
        return dp[i][j + 1] = max(take, notTake);
    }

    static bool cmp(string& a, string& b) {
        return a.size() < b.size();
    }
    
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), cmp);
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return helper(-1, 0, words, dp);
    }
};