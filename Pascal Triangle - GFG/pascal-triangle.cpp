//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
// #define ll long long
class Solution{
public:
    vector<ll> nthRowOfPascalTriangle(int n) {
        vector<vector<ll>> res;
        ll M = 1e9 + 7;
        for (int i = 0; i < n; i++)
        {
            vector<ll> temp(i + 1, 1);
            for (int j = 0; j < i / 2; j++)
            {
                temp[j + 1] = (res[i - 1][j] + res[i - 1][j + 1]) % M;
                temp[i - j - 1] = temp[j + 1] % M;
            }
            res.push_back(temp);
        }
        return res[n - 1];
    }
};


//{ Driver Code Starts.


void printAns(vector<ll> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends