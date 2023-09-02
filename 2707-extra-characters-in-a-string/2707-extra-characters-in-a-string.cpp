class Solution {
public:
    int helper(int ind, string& s, unordered_map<string, bool>& seen, vector<int>& dp) {
        if(ind == s.size()) {
            return 0;
        }
        if(dp[ind] != -1) {
            return dp[ind];
        }

        int take = 1e9;
        for (int i = ind; i < s.size(); i++)
        {
            int size = i - ind + 1;
            string ss = s.substr(ind, size);
            if(seen[ss]) {
                take = min(take, helper(i + 1, s, seen, dp));
            }
        }
        int notTake = 1 + helper(ind + 1, s, seen, dp);
        return dp[ind] = min(take, notTake);
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_map<string, bool> seen;
        for (int i = 0; i < dictionary.size(); i++)
        {
            seen[dictionary[i]] = 1;
        }
        vector<int> dp(s.size(), -1);
        return helper(0, s, seen, dp);
    }
};