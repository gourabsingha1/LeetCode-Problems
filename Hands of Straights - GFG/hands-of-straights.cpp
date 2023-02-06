//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isStraightHand(int n, int groupSize, vector<int> &hand) {
        if(n % groupSize) return 0;
        map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            m[hand[i]]++;
        }
        sort(hand.begin(), hand.end());
        for (int i = 0; i < n; i++)
        {
            if(!m[hand[i]]) continue;
            for (int j = 0; j < groupSize; j++)
            {
                if(!m[hand[i] + j]--) return 0;
            }
        }
        return 1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, groupSize;
        cin >> N >> groupSize;

        vector<int> hand(N);
        for (int i = 0; i < N; i++) cin >> hand[i];

        Solution obj;
        int ans = obj.isStraightHand(N, groupSize, hand);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends