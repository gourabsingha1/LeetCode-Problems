//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
    // memoization
    int helper(int i, int* nums, vector<int>& dp) {
        if(i == 0) {
            return nums[0];
        }
        else if(i < 0) {
            return 0;
        }
        else if(dp[i] != -1) {
            return dp[i];
        }
        int prev1 = nums[i] + helper(i - 2, nums, dp);
        int prev2 = 0 + helper(i - 1, nums, dp);
        return dp[i] = max(prev1, prev2);
    }
    int findMaxSum(int *arr, int n) {
        vector<int> dp(n, -1);
        return helper(n - 1, arr, dp);
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