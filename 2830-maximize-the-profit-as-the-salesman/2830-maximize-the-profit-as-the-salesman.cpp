class Solution {
public:
    int helper(vector<int>& temp, int i, vector<vector<int>>& offers, vector<int>& dp) {
        if(i >= offers.size()) {
            return 0;
        }
        if(dp[i] != -1) {
            return dp[i];
        }
        
        int j = lower_bound(temp.begin(), temp.end(), offers[i][1] + 1) - temp.begin();
        int take = offers[i][2] + helper(temp, j, offers, dp);
        int notTake = helper(temp, i + 1, offers, dp);
        return dp[i] = max(take, notTake);
    }

    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        sort(offers.begin(), offers.end());
        vector<int> dp(offers.size(), -1), temp;
        for(auto& offer : offers) {
            temp.push_back(offer[0]);
        }
        return helper(temp, 0, offers, dp);
    }
};