//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
    // space optimization
    int findMaxSum(int *arr, int n) {
        int prev1 = arr[0], prev2 = 0;
        for (int i = 1; i < n; i++)
        {
            int take = arr[i] + prev2;
            int notTake = 0 + prev1;
            prev2 = prev1;
            prev1 = max(take, notTake);
        }
        return prev1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends