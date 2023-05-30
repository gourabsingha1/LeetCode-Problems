//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
#define ll long long
class Solution {
public:
    // memoization
    ll helper(int coins[], int n, int amount, vector<vector<ll>>& dp) {
        if(n < 0 || amount <= 0) {
            return amount == 0;
        }
        if(dp[n][amount] != -1) {
            return dp[n][amount];
        }
        ll take = helper(coins, n, amount - coins[n], dp);
        ll notTake = helper(coins, n - 1, amount, dp);
        return dp[n][amount] = take + notTake;
    }

    long long int count(int coins[], int n, int amount) {
        vector<vector<ll>> dp(n, vector<ll> (amount + 1, -1));
        return helper(coins, n - 1, amount, dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends