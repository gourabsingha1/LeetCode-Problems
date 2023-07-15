// sort the events by the start time and in case of tie by the end time in ascending order
// take / notTake and find next index using binary search

class Solution {
public:
    int nextIndex(int& i, vector<vector<int>>& events) {
        int low = i, high = events.size() - 1, prevDay = events[i][1]; 
        while(low <= high) {
            int mid = high + (low - high) / 2, curDay = events[mid][0];
            if(curDay <= prevDay) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return low;
    }

    int helper(int i, vector<vector<int>>& events, int k, vector<vector<int>>& dp) {
        if(i >= events.size() || k == 0) {
            return 0;
        }
        if(dp[i][k] != -1) {
            return dp[i][k];
        }

        int value = events[i][2];
        int j = nextIndex(i, events);
        int take = value + helper(j, events, k - 1, dp);
        int notTake = helper(i + 1, events, k, dp);
        return dp[i][k] = max(take, notTake);
    }

    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        sort(events.begin(), events.end());
        vector<vector<int>> dp(n, vector<int> (k + 1, -1));
        return helper(0, events, k, dp);
    }
};