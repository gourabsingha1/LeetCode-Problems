//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    // memoization
    int helper(int W, int wt[], int val[], int n, vector<vector<int>>& dp) {
        if(n < 0) {
            return 0;
        }
        if(dp[n][W] != -1) {
            return dp[n][W];
        }
        int take = INT_MIN;
        if(W - wt[n] >= 0) {
            take = val[n] + helper(W - wt[n], wt, val, n, dp);
        }
        int notTake = helper(W, wt, val, n - 1, dp);
        return dp[n][W] = max(take, notTake);
    }
    int knapSack(int N, int W, int val[], int wt[]) 
    {
        vector<vector<int>> dp(N, vector<int> (W + 1, -1));
        return helper(W, wt, val, N - 1, dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends