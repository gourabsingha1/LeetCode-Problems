//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
    // tabulation
    int findMaxSum(int *arr, int n) {
        vector<int> dp(n);
        dp[0] = arr[0];
        int prev1 = arr[1], prev2 = 0;
        for (int i = 1; i < n; i++)
        {
            if(i > 1) {
                prev1 = arr[i] + dp[i - 2];
            }
            prev2 = 0 + dp[i - 1];
            dp[i] = max(prev1, prev2);
        }
        return dp[n - 1];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends