// brute force

class Solution {
public:
    int dp[1001];

    int helper(int ind, vector<int>& arr, int& d) {
        if(dp[ind] != -1) {
            return dp[ind];
        }

        int res = 0;
        for (int i = ind + 1; i <= min((int)arr.size() - 1, ind + d) && arr[ind] > arr[i]; i++)
        {
            res = max(res, 1 + helper(i, arr, d));
        }
        for (int i = ind - 1; i >= max(0, ind - d) && arr[ind] > arr[i]; i--)
        {
            res = max(res, 1 + helper(i, arr, d));
        }
        return dp[ind] = res;
    }

    int maxJumps(vector<int>& arr, int d) {
        int res = 0, n = arr.size();
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < n; i++)
        {
            res = max(res, helper(i, arr, d));
        }
        return res + 1;
    }
};