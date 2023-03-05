//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

long long int dp[100001], M = 1e9 + 7;
class Solution {
  public:
    // memoization
    long long int topDown(int n) {
        if(n < 2) {
            return n;
        }
        else if(dp[n] != -1) {
            return dp[n];
        }
        long long int prev1 = topDown(n - 1);
        long long int prev2 = topDown(n - 2);
        return dp[n] = (prev1 + prev2) % M;
    }
    // tabulation
    long long int bottomUp(int n) {
        vector<long long int> dp(n + 1);
        dp[0] = 0, dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            long long int prev1 = dp[i - 1];
            long long int prev2 = dp[i - 2];
            dp[i] = (prev1 + prev2) % M;
        }
        return dp[n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        for (int i = 0; i < 100001; i++) dp[i] = -1;
        int n;
        cin >> n;
        Solution obj;
        long long int topDownans = obj.topDown(n);
        long long int bottomUpans = obj.bottomUp(n);
        if (topDownans != bottomUpans) cout << -1 << "\n";
        cout << topDownans << "\n";
    }
}
// } Driver Code Ends