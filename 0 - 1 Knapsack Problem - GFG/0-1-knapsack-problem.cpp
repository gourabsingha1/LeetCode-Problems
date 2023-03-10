//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    // memoization
    int helper(int W, int wt[], int val[], int n, vector<vector<int>>& dp) {
        if(n < 0) {
            return 0;
        }
        if(dp[n][W]) {
            return dp[n][W];
        }
        int take = INT_MIN;
        if(W - wt[n] >= 0) {
            take = helper(W - wt[n], wt, val, n - 1, dp) + val[n];
        }
        int notTake = helper(W, wt, val, n - 1, dp);
        return dp[n][W] = max(take, notTake);
    }
    int knapSack(int W, int wt[], int val[], int n) 
    {
        vector<vector<int>> dp(n, vector<int> (W + 1, 0));
        return helper(W, wt, val, n - 1, dp);
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
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends