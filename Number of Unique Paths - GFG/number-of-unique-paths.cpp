//{ Driver Code Starts
//Initial template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template in C++

class Solution
{
    public:
    // memoization
    int helper(int n, int m, vector<vector<int>>& dp) {
        if(n == 0 && m == 0) {
            return 1;
        }
        if(n < 0 || m < 0) {
            return 0;
        }
        if(dp[n][m] != -1) {
            return dp[n][m];
        }
        return dp[n][m] = helper(n - 1, m, dp) + helper(n, m - 1, dp);
    }
    int NumberOfPath(int n, int m)
    {
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return helper(n - 1, m - 1, dp);
    }
};


//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking dimensions of the matrix
        int a,b;
        cin>>a>>b;
        Solution ob;
        //calling NumberOfPath() function
        cout << ob.NumberOfPath(a,b) << endl;
    }
}


// } Driver Code Ends