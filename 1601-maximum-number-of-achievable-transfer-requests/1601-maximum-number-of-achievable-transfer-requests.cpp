// try all combinations of requests. if achievable, add to result

class Solution {
public:
    bool isAchievable(int& subset, int& n, vector<vector<int>>& requests) {
        vector<int> buildings(n, 0);
        for (int i = 0; i < requests.size(); i++)
        {
            int mask = 1 << i;
            if(subset & mask) {
                int from = requests[i][0], to = requests[i][1];
                buildings[from]--, buildings[to]++;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if(buildings[i]) {
                return 0;
            }
        }
        return 1;
    }

    int helper(int& subset, int ind, int& n, vector<vector<int>>& requests, vector<vector<int>>& dp) {
        if(ind < 0) {
            if(!isAchievable(subset, n, requests)) {
                return 0;
            }
            int size = __builtin_popcount(subset);
            return size;
        }
        if(dp[subset][ind] != -1) {
            return dp[subset][ind];
        }

        int mask = 1 << ind;
        subset += mask;
        int take = helper(subset, ind - 1, n, requests, dp);
        subset -= mask;
        int notTake = helper(subset, ind - 1, n, requests, dp);
        return dp[subset][ind] = max(take, notTake);
    }
    
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int m = requests.size();
        vector<vector<int>> dp((1 << m) + 1, vector<int> (m, -1));
        int subset = 0;
        return helper(subset, requests.size() - 1, n, requests, dp);
    }
};