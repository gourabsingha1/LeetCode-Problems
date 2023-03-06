//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // memoization
    int helper(int row, int col, vector<vector<int>>& points, int n, vector<vector<int>>& dp) {
        if(row == n) {
            return 0;
        }
        if(dp[row][col]) {
            return dp[row][col];
        }
        int one = helper(row + 1, (col + 1) % 3, points, n, dp);
        int two = helper(row + 1, (col + 2) % 3, points, n, dp);
        return dp[row][col] = max(one, two) + points[row][col];
    }
    int maximumPoints(vector<vector<int>>& points, int n) {
        int res = 0;
        vector<vector<int>> dp(n, vector<int> (3));
        for (int i = 0; i < 3; i++)
        {
            res = max(res, helper(0, i, points, n, dp));
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