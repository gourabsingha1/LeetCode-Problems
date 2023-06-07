//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

// tabulation
class Solution{
public:
    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>> dp(N, vector<int> (N, 0));
        for (int i = N - 1; i >= 1; i--)
        {
            for (int j = i + 1; j < N; j++)
            {
                if(i == j) continue;
                
                int res = INT_MAX;
                for (int k = i; k < j; k++)
                {
                    int cost = arr[i - 1] * arr[k] * arr[j];
                    int left = dp[i][k];
                    int right = dp[k + 1][j];
                    res = min(res, cost + left + right);
                }
                dp[i][j] = res;
            }
        }
        return dp[1][N - 1];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends