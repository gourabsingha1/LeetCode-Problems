//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    int helper(int i, int j, vector<int>& nums, vector<vector<int>>& dp) {
        if(i > j) {
            return 0;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        int res = INT_MIN;
        for (int k = i; k <= j; k++)
        {
            int left = helper(i, k - 1, nums, dp);
            int right = helper(k + 1, j, nums, dp);
            int cost = nums[i - 1] * nums[k] * nums[j + 1] + left + right;
            res = max(res, cost);
        }
        return dp[i][j] = res;
    }

    int maxCoins(int N, vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return helper(1, n - 2, nums, dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        vector<int> arr(N);
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution obj;
        cout << obj.maxCoins(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends