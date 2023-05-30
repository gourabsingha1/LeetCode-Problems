//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int M = 1e9 + 7;
    int helper(int n, int sum, int nums[], vector<vector<int>>& dp) {
        if(sum < 0) {
            return 0;
        }
        if(n < 0) {
            return sum == 0;
        }
        if(dp[n][sum] != -1) {
            return dp[n][sum];
        }
        int take = helper(n - 1, sum - nums[n], nums, dp);
        int notTake = helper(n - 1, sum, nums, dp);
        return dp[n][sum] = (take + notTake) % M;
    }
    int perfectSum(int nums[], int n, int sum)
	{
        vector<vector<int>> dp(n, vector<int> (sum + 1, -1));
        return helper(n - 1, sum, nums, dp);
	}
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends