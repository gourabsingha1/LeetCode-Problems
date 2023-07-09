class Solution {
public:
    bool helper(int k, int i, vector<int>& stones, unordered_map<int, int>& mp, vector<vector<int>>& dp) {
        if(i == stones.size() - 1) {
            return 1;
        }
        if(dp[i][k] != -1) {
            return dp[i][k];
        }

        bool one = 0, two = 0, three = 0;
        if(k - 1 > 0 && mp[stones[i] + k - 1]) {
            one = helper(k - 1, mp[stones[i] + k - 1], stones, mp, dp);
        }
        if(k > 0 && mp[stones[i] + k]) {
            two = helper(k, mp[stones[i] + k], stones, mp, dp);
        }
        if(mp[stones[i] + k + 1]) {
            three = helper(k + 1, mp[stones[i] + k + 1], stones, mp, dp);
        }

        bool res = one || two || three;
        return dp[i][k] = res;
    }

    bool canCross(vector<int>& stones) {
        unordered_map<int, int> mp;
        int n = stones.size();
        for (int i = 0; i < n; i++)
        {
            mp[stones[i]] = i;
        }
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return helper(0, 0, stones, mp, dp);
    }
};