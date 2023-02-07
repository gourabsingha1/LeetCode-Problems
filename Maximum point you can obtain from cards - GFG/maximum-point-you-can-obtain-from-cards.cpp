//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long maxScore(vector<int>& cardPoints, int n, int k) {
        long long res = 0, curr = accumulate(cardPoints.begin(), cardPoints.end(), 0);
        if(k == n){
            return curr;
        }
        k = n - k;
        for (int i = 0, j = 0; i < n; i++)
        {
            curr -= cardPoints[i];
            if(i + 1 >= k){
                res = max(res, curr);
                curr += cardPoints[j++];
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, k;
        cin >> N >> k;

        vector<int> cardPoints(N);
        for (int i = 0; i < N; i++) cin >> cardPoints[i];

        Solution obj;
        cout << obj.maxScore(cardPoints, N, k) << endl;
    }
    return 0;
}
// } Driver Code Ends