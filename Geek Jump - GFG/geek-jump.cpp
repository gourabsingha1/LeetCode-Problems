//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    vector<int> dp;
    int helper(vector<int>& height, int n) {
        if(n == 0) {
            return 0;
        }
        else if(dp[n] != -1) {
            return dp[n];
        }
        int left = helper(height, n - 1) + abs(height[n] - height[n - 1]);
        int right = 1e9;
        if(n > 1) {
            right = helper(height, n - 2) + abs(height[n] - height[n - 2]);
        }
        return dp[n] = min(left, right);
    }
    int minimumEnergy(vector<int>& height, int n) {
        dp.resize(n, -1);
        return helper(height, n - 1);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends