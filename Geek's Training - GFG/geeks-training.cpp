//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // memoization
    int helper(int day, int last, vector<vector<int>>& points, vector<vector<int>>& dp) {
        if(day < 0) {
            return 0;
        }
        if(dp[day][last]) {
            return dp[day][last];
        }
        int res = 0;
        for (int i = 0; i < 3; i++)
        {
            if(i != last) {
                res = max(res, points[day][i] + helper(day - 1, i, points, dp));
            }
        }
        return dp[day][last] = res;
    }
    int maximumPoints(vector<vector<int>>& points, int n) {
        vector<vector<int>> dp(n, vector<int> (3));
        int res = 0;
        for (int i = 0; i < 3; i++)
        {
            res = max(res, helper(n - 1, i, points, dp));
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> points;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            points.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(points, n) << endl;
    }
    return 0;
}
// } Driver Code Ends