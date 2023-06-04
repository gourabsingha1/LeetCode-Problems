//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
public:
    int helper(int n, int m, string& text1, string& text2, vector<vector<int>>& dp) {
        if(n < 0 || m < 0) {
            return 0;
        }
        if(dp[n][m] != -1) {
            return dp[n][m];
        }
        int res = 0;
        if(text1[n] == text2[m]) {
            res = 1 + helper(n - 1, m - 1, text1, text2, dp);
        }
        else {
            int first = helper(n - 1, m, text1, text2, dp);
            int second = helper(n, m - 1, text1, text2, dp);
            res = max(first, second);
        }
        return dp[n][m] = res;
    }
    int lcs(int n, int m, string text1, string text2)
    {
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return helper(n - 1, m - 1, text1, text2, dp);
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends