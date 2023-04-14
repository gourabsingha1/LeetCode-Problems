//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    // tabulation
    int equalPartition(int n, int nums[]) {
        int sum = accumulate(nums, nums + n, 0);
        if(sum & 1) {
            return 0;
        }
        sum /= 2;
        vector<vector<int>> dp(n, vector<int> (sum + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= sum; j++)
            {
                if(j == 0) {
                    dp[i][j] = 1;
                }
                else {
                    bool take = 0;
                    if(j - nums[i] >= 0) {
                        take = dp[i - 1][j - nums[i]];
                    }
                    bool notTake = dp[i - 1][j];
                    dp[i][j] = take || notTake;
                }
            }
        }
        return dp[n - 1][sum];
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
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends