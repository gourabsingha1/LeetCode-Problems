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
    
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        sort(events.begin(), events.end());
        vector<vector<int>> dp(n + 1, vector<int> (k + 1, 0));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 0; j <= k; j++)
            {
                if(j == 0) {
                    dp[i][j] = 0;
                }
                else {
                    int value = events[i][2];
                    int ind = nextIndex(i, events);
                    int take = value + dp[ind][j - 1];
                    int notTake = dp[i + 1][j];
                    dp[i][j] = max(take, notTake);
                }
            }
        }
        return dp[0][k];
    }
};