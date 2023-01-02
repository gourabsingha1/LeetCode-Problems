//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void helper(int k, int n, int currInd, vector<int> v, vector<vector<int>> &res){
        if(n <= 0 || v.size() >= k){
            if(!n && v.size() == k) res.push_back(v);
            return;
        }
        for (int i = currInd; i <= 9; i++)
        {
            v.push_back(i);
            n -= i;
            helper(k, n, i+1, v, res);
            v.pop_back();
            n += i;
        }
    }

    vector<vector<int>> combinationSum(int K, int N) {
        vector<vector<int>> res;
        helper(K, N, 1, {}, res);
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K >> N;

        Solution obj;
        vector<vector<int>> ans = obj.combinationSum(K, N);
        sort(ans.begin(), ans.end());
        for (auto &arr : ans) {
            for (auto it : arr) cout << it << ' ';
            cout << endl;
        }
    }
    return 0;
}
// } Driver Code Ends