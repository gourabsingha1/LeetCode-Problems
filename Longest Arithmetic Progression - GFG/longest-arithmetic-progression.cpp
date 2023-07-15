//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

// nums[i] = last element, nums[j] = second last element
// store the count of prev elements in the map of {current element index, diff}
// to get the longest subsequence in O(1)

class Solution {
public:
    int lengthOfLongestAP(int nums[], int n) {
        if(n < 3) {
            return n;
        }
        
        int res = 1;
        vector<vector<int>> dp(n, vector<int> (10001, 0));
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                int diff = nums[i] - nums[j];
                int tempRes = 1 + dp[j][diff];
                dp[i][diff] = tempRes;
                res = max(res, dp[i][diff]);
            }
        }
        return res + 1;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        Solution ob;
        auto ans = ob.lengthOfLongestAP(A, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends