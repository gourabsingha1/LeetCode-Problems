//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	void rearrange(int nums[], int n) {
        vector<int> pos, neg, res;
        for (int i = 0; i < n; i++)
        {
            if(nums[i] < 0) neg.push_back(nums[i]);
            else pos.push_back(nums[i]);
        }
        for (int i = 0, j = 0, k = 0; i < n; i++)
        {
            if(i % 2 == 0 && j < pos.size() || k == neg.size()){
                res.push_back(pos[j++]);
            }
            else{
                res.push_back(neg[k++]);
            }
        }
        for (int i = 0; i < n; i++)
        {
            nums[i] = res[i];
        }
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends