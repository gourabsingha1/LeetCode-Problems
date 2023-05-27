class Solution {
public:
    int helper(int ind, bool alice, vector<int>& stoneValue, vector<vector<int>>& dp) {
        if(ind == stoneValue.size()) {
            return 0;
        }
        if(dp[ind][alice] != -1) {
            return dp[ind][alice];
        }
        
        int res = INT_MIN, sum = 0, size = min(ind + 3, (int) stoneValue.size());
        if(!alice) res = INT_MAX;
        for (int i = ind; i < size; i++)
        {
            sum += stoneValue[i];
            if(alice) {
                res = max(res, sum + helper(i + 1, !alice, stoneValue, dp));
            }
            else {
                res = min(res, helper(i + 1, !alice, stoneValue, dp)); // the helper function returns alice's score and we dont add her score to bob's. thats why we dont add the sum. bob minimizes alice's score
            }
        }
        return dp[ind][alice] = res;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size(), sum = accumulate(stoneValue.begin(), stoneValue.end(), 0);
        vector<vector<int>> dp(n, vector<int> (2, -1));
        int alice = helper(0, 1, stoneValue, dp);
        if(2 * alice > sum) {
            return "Alice";
        }
        else if(2 * alice < sum) {
            return "Bob";
        }
        return "Tie";
    }
};