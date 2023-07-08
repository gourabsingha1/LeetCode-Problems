// knapsack problem. if you picked an interval at index i,
// you have to pick another interval with startTime[j] >= endTime[i]
// can binary search on j

class Solution {
public:
    int helper(int i, vector<int>& startTime, vector<vector<int>>& datas, vector<int>& dp) {
        if(i == startTime.size()) {
            return 0;
        }
        if(dp[i] != -1) {
            return dp[i];
        }

        int j = lower_bound(startTime.begin(), startTime.end(), datas[i][1]) - startTime.begin();
        int take = datas[i][2] + helper(j, startTime, datas, dp);
        int notTake = helper(i + 1, startTime, datas, dp);
        return dp[i] = max(take, notTake);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> datas;
        for (int i = 0; i < startTime.size(); i++)
        {
            datas.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(datas.begin(), datas.end());
        sort(startTime.begin(), startTime.end());
        vector<int> dp(startTime.size(), -1);
        return helper(0, startTime, datas, dp);
    }
};